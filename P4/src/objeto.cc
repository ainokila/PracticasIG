#include"objeto.h"
#include<iostream>
#include "file_ply_stl.h"
#include <unistd.h>
#include <math.h>


Objeto::Objeto(){

  modoPintado = 2;
  modePolygon = GL_FILL;
  bound = BoundingBox();
}
void Objeto::dibujar(){

  if(modoPintado==3){
    std::vector<float> color1;
    for(int i = 0; i<puntos.size();i = i + 3){
      color1.push_back(0.35f);
      color1.push_back(0.33f);
      color1.push_back(0.15f);

    }

    std::vector<float> color2;
    for(int i = 0; i<puntos.size();i = i + 3){
      color2.push_back(0.6f);
      color2.push_back(0.5f);
      color2.push_back(0.5f);
    }

    //glScalef(80,80,80);

    glEnable(GL_CULL_FACE);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3,GL_FLOAT,0,&(puntos[0]));
    glPolygonMode(GL_FRONT_AND_BACK,modePolygon);

    glEnableClientState(GL_COLOR_ARRAY);
    glColorPointer(3,GL_FLOAT,0,&color1[0]);
    glDrawElements(GL_TRIANGLES,caras.size()/2,GL_UNSIGNED_INT,&(caras[0]));
    glDisableClientState(GL_COLOR_ARRAY);

    glEnableClientState(GL_COLOR_ARRAY);
    glColorPointer(3,GL_FLOAT,0,&color2[0]);
    glDrawElements(GL_TRIANGLES,caras.size()/2,GL_UNSIGNED_INT,&(caras[caras.size()/2]));
    glDisableClientState(GL_COLOR_ARRAY);


    glDisableClientState(GL_VERTEX_ARRAY);



  }else{

    //glTranslatef(-bound.centroX(),-bound.centroY(),-bound.centroZ());
    //std::cout << -bound.centroX() << " " << -bound.centroY() << " " << -bound.centroZ() << endl;
    //glScalef(10.0f*bound.ladoX(),10.0f*bound.ladoY(),10.0f*bound.ladoZ());
    //std::cout << bound.ladoX() << " " << bound.ladoY() << " " << bound.ladoZ() << std::endl;
    //bound.imprimeDatos();
    //glScalef(12,12,12);
    //std::cout << bound.diffX()*1e+38 << " " << bound.diffY()*1e+38 << " " << bound.diffZ()*1e+38 << " " << std::endl ;
    /*
    std::vector<float> color1;
    for(int i = 0; i<puntos.size();i = i + 3){
      color1.push_back(0.35f);
      color1.push_back(0.33f);
      color1.push_back(0.15f);
    }

    glPointSize(1.0f);
    glEnable(GL_CULL_FACE);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3,GL_FLOAT,0,&(puntos[0]));
    glPolygonMode(GL_FRONT_AND_BACK,modePolygon);
    glColorPointer(3,GL_FLOAT,0,&color1[0]);
    glDrawElements(GL_TRIANGLES,caras.size(),GL_UNSIGNED_INT,&(caras[0]));
    glDisableClientState(GL_VERTEX_ARRAY);
    */
    if(modePolygon == GL_FILL){
      std::vector<float> color2;
      for(int i = 0; i<puntos.size();i = i + 3){
        color2.push_back(1.0f);
        color2.push_back(1.0f);
        color2.push_back(1.0f);
      }
      glPointSize(1.0f);
      glEnable(GL_CULL_FACE);
      glEnableClientState(GL_VERTEX_ARRAY);
      glVertexPointer(3,GL_FLOAT,0,&(puntos[0]));
      glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
      glColorPointer(3,GL_FLOAT,0,&color2[0]);
      glDrawElements(GL_TRIANGLES,caras.size(),GL_UNSIGNED_INT,&(caras[0]));
      glDisableClientState(GL_VERTEX_ARRAY);
    }

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

  auxiliarNormal = puntos;
  normalesPuntos = puntos;

  //Pongo los elementos a 0
  std::fill(auxiliarNormal.begin(), auxiliarNormal.end(), 0.0f);
  std::fill(normalesPuntos.begin(), normalesPuntos.end(), 0.0f);

  //auxiliarNormal.push_back(0);
  //auxiliarNormal.push_back(0);
  //auxiliarNormal.push_back(0);

}

//Funcion no probada aun
void Objeto::calcularNormalesPuntos(){
  float x,y,z,norm,mod;
  for(int i = 0; i < puntos.size()-3;i = i +3){
    x = normalesPuntos[i];y = normalesPuntos[i+1];z = normalesPuntos[i+2];
    mod = sqrt(pow(x,2)+pow(y,2)+pow(z,2));

    normalesPuntos[i] = x/mod;
    normalesPuntos[i+1] = y/mod;
    normalesPuntos[i+2] = z/mod;
  }
}


void Objeto::insertarCara(int v1, int v2, int v3){
    caras.push_back(v1);
    caras.push_back(v2);
    caras.push_back(v3);

    //Calculo la normal para esa cara ->

    //Obtenemos el valor de los puntos
    float p_x = puntos.at(v1*3);
    float p_y = puntos.at(v1*3+1);
    float p_z = puntos.at(v1*3+2);
    float q_x = puntos.at(v2*3);
    float q_y = puntos.at(v2*3+1);
    float q_z = puntos.at(v2*3+2);
    float r_x = puntos.at(v3*3);
    float r_y = puntos.at(v3*3+1);
    float r_z = puntos.at(v3*3+2);

    float a_x,a_y,a_z,b_x,b_y,b_z,m_x,m_y,m_z,n_x,n_y,n_z,mod;

    //Calculamos a = q - p
    a_x = q_x - p_x;
    a_y = q_y - p_y;
    a_z = q_z - p_z;

    //Calculamos b = r - p
    b_x = r_x - p_x;
    b_y = r_y - p_y;
    b_z = r_z - p_z;

    //Realizo el producto vectorial

    m_x = a_x*b_z-a_z*b_y;
    m_y = a_x*b_z-a_z*b_x;
    m_z = a_x*b_y-a_y*b_x;

    //Calculo la normal

    mod = sqrt(pow(m_x,2)+pow(m_y,2)+pow(m_z,2));
    n_x = m_x / mod;
    n_y = m_y / mod;
    n_z = m_z / mod;

    normalesCaras.push_back(n_x);
    normalesCaras.push_back(n_y);
    normalesCaras.push_back(n_z);

    std::cout << n_x << " " << n_y << " " << n_z << " " << std::endl;

    //Sumar y Almacenar en una estructura auxiliar las normales en v1,v2,v3 para luego normalizar

    auxiliarNormal[v1*3] = auxiliarNormal[v1*3] + n_x;
    auxiliarNormal[v1*3+1] = auxiliarNormal[v1*3+1] + n_y;
    auxiliarNormal[v1*3+2] = auxiliarNormal[v1*3+2] + n_z;

    auxiliarNormal[v2*3] = auxiliarNormal[v2*3] + n_x;
    auxiliarNormal[v2*3+1] = auxiliarNormal[v2*3+1] + n_y;
    auxiliarNormal[v2*3+2] = auxiliarNormal[v2*3+2] + n_z;

    auxiliarNormal[v3*3] = auxiliarNormal[v3*3] + n_x;
    auxiliarNormal[v3*3+1] = auxiliarNormal[v3*3+1] + n_y;
    auxiliarNormal[v3*3+2] = auxiliarNormal[v3*3+2] + n_z;


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
