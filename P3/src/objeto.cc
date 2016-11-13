#include"objeto.h"
#include<iostream>
#include "file_ply_stl.h"
#include <unistd.h>


Objeto::Objeto(){

  modoPintado = 2;
  modePolygon = GL_FILL;
  bound = BoundingBox();
}
void Objeto::dibujar(){

  if(modoPintado==3){
    std::vector<float> cara1;
    for(int i = 0; i<puntos.size();i = i + 3){
      cara1.push_back(0.35f);
      cara1.push_back(0.33f);
      cara1.push_back(0.15f);

    }

    std::vector<float> cara2;
    for(int i = 0; i<puntos.size();i = i + 3){
      cara2.push_back(0.6f);
      cara2.push_back(0.5f);
      cara2.push_back(0.5f);
    }

    //glScalef(80,80,80);

    glEnable(GL_CULL_FACE);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3,GL_FLOAT,0,&(puntos[0]));
    glPolygonMode(GL_FRONT_AND_BACK,modePolygon);

    glEnableClientState(GL_COLOR_ARRAY);
    glColorPointer(3,GL_FLOAT,0,&cara1[0]);
    glDrawElements(GL_TRIANGLES,caras.size()/2,GL_UNSIGNED_INT,&(caras[0]));
    glDisableClientState(GL_COLOR_ARRAY);

    glEnableClientState(GL_COLOR_ARRAY);
    glColorPointer(3,GL_FLOAT,0,&cara2[0]);
    glDrawElements(GL_TRIANGLES,caras.size()/2,GL_UNSIGNED_INT,&(caras[caras.size()/2]));
    glDisableClientState(GL_COLOR_ARRAY);


    glDisableClientState(GL_VERTEX_ARRAY);



  }else{

    std::vector<float> cara1;
    for(int i = 0; i<puntos.size();i = i + 3){
      cara1.push_back(0.35f);
      cara1.push_back(0.33f);
      cara1.push_back(0.15f);
    }

    //glTranslatef(-bound.centroX(),-bound.centroY(),-bound.centroZ());
    //std::cout << -bound.centroX() << " " << -bound.centroY() << " " << -bound.centroZ() << endl;
    //glScalef(10.0f*bound.ladoX(),10.0f*bound.ladoY(),10.0f*bound.ladoZ());
    //std::cout << bound.ladoX() << " " << bound.ladoY() << " " << bound.ladoZ() << std::endl;
    //bound.imprimeDatos();
    //glScalef(12,12,12);
    //std::cout << bound.diffX()*1e+38 << " " << bound.diffY()*1e+38 << " " << bound.diffZ()*1e+38 << " " << std::endl ;

    glPointSize(1.0f);
    glEnable(GL_CULL_FACE);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3,GL_FLOAT,0,&(puntos[0]));
    glPolygonMode(GL_FRONT_AND_BACK,modePolygon);
    glColorPointer(3,GL_FLOAT,0,&cara1[0]);
    glDrawElements(GL_TRIANGLES,caras.size(),GL_UNSIGNED_INT,&(caras[0]));
    glDisableClientState(GL_VERTEX_ARRAY);

    //bound.imprimeDatos();
    //std::cout << puntos.size() << std::endl;

    //for(int i = 0 ; i < 10 ; i++)
    //  std::cout << puntos[i] << " ";

    //VISUALIZAR puntos
    /*
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3,GL_FLOAT,0,&(puntos[0]));
    glDrawArrays(GL_POINTS,0,puntos.size());
    glDisableClientState(GL_VERTEX_ARRAY);*/
  }
}

void Objeto::cambiarDibujado(int nuevo){ //0 puntos 1 lineas 2 solido 3 ajedrez
  modoPintado = nuevo;

  switch (nuevo) {
    case 0:
      modePolygon = GL_POINT;
      break;
    case 1:
      modePolygon = GL_LINE;
      break;
    default:
      modePolygon = GL_FILL;
      break;
  }
}


void Objeto::insertarVertice(float x,float y,float z){
  puntos.push_back(x);
  bound.nuevaX(x);
  puntos.push_back(y);
  bound.nuevaY(y);
  puntos.push_back(z);
  bound.nuevaZ(z);
}

void Objeto::insertarCara(int v1, int v2, int v3){
    caras.push_back(v1);
    caras.push_back(v2);
    caras.push_back(v3);
}

// INICIO ÑAPA
void Objeto::ampliar(){
  //glTranslatef((bound.getMaxX()+bound.getMinX())/2.0f,(bound.getMaxY()+bound.getMinY())/2.0f,(bound.getMaxZ()+bound.getMinZ())/2.0f);
  //glScalef((bound.getMaxX()+bound.getMinX())*1e+38,(bound.getMaxY()+bound.getMinY())*1e+38,(bound.getMaxZ()+bound.getMinZ())*1e+38);

  /*for(int i = 0 ; i < puntos.size() ; i++){
    puntos[i]*=1.25f;
  }
  bound.calcularBoundingBox(puntos);*/
  glScalef(2.0f,2.0f,2.0f);
}

void Objeto::reducir(){
  /*for(int i = 0 ; i < puntos.size() ; i++){
    puntos[i]/=1.25f;
  }
  bound.calcularBoundingBox(puntos);*/
  glScalef(0.5f,0.5f,0.5f);

}
//FIN ÑAPA
void Objeto::leerPly(){
  std::string str;
  std::cout << "Introduzca la direccion del PLY: " << std::endl;
  cin >> str;

  if (access( str.c_str(), F_OK ) != -1) {

      _file_ply *ply;
      ply = new _file_ply();
      std::vector<char> cstr(str.c_str(), str.c_str() + str.size() + 1);
      ply->open(&cstr[0]);
      std::vector<float> vertices;
      std::vector<int> caras;
      ply->read(vertices,caras);

      setPuntos(vertices);
      bound.calcularBoundingBox(vertices);
      setCaras(caras);

  } else {
      std::cerr << "Error , el archivo no existe" << std::endl;
      leerPly();
  }

}
