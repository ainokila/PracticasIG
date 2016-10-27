#include"objeto.h"
#include<iostream>
#include "file_ply_stl.h"
#include <unistd.h>


Objeto::Objeto(){

  modoPintado = 2;
  modePolygon = GL_FILL;
  bound = BoundingBox();
  vertices.clear();
}
void Objeto::dibujar(){

  glColor3f(0.35,0.33,0.15);
  glPointSize(1.0f);
  glEnable(GL_CULL_FACE);

  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3,GL_FLOAT,0,&(vertices[0]));
  glPolygonMode(GL_FRONT_AND_BACK,modePolygon);
  glDrawElements(GL_TRIANGLES,caras.size()*3,GL_UNSIGNED_INT,&(caras[0]));
  glDisableClientState(GL_VERTEX_ARRAY);
  //bound.imprimeDatos();
  //std::cout << puntos.size() << std::endl;

  //for(int i = 0 ; i < 10 ; i++)
  //  std::cout << puntos[i] << " ";
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
  Vertice v;
  v.x = x;
  v.y = y;
  v.z = z;
  bound.nuevaX(x);
  bound.nuevaX(y);
  bound.nuevaX(z);
  vertices.push_back(v);
}

void Objeto::insertarCara(int v1, int v2, int v3){
    Cara c;
    c.v1 = v1;
    c.v2 = v2;
    c.v3 = v3;
    caras.push_back(c);
}

// INICIO ÑAPA
void Objeto::ampliar(){
  for(int i = 0 ; i < vertices.size() ; i++){
    vertices[i].x*=1.25;
    vertices[i].y*=1.25;
    vertices[i].z*=1.25;
  }
  bound.calcularBoundingBox(vertices);
}

void Objeto::reducir(){
  for(int i = 0 ; i < vertices.size() ; i++){
    vertices[i].x=1.25;
    vertices[i].y=1.25;
    vertices[i].z=1.25;
  }
  bound.calcularBoundingBox(vertices);
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
      std::vector<float> v;
      std::vector<int> c;
      ply->read(v,c);

      std::cout<<vertices.size();
      //setPuntos(vertices);
      /*
      for(int i=0; i < v.size()-3 ;i = i + 3){
        Vertice aux;
        aux.x = v[i];
        aux.y = v[i+1];
        aux.z = v[i+2];
        vertices.push_back(aux);
      }
      bound.calcularBoundingBox(vertices);
      //setCaras(caras);

      for(int i=0; i < c.size()-3 ;i = i + 3){
        Cara aux;
        aux.v1 = c[i];
        aux.v2 = c[i+1];
        aux.v3 = c[i+2];
        caras.push_back(aux);
      }*/

  } else {
      std::cerr << "Error , el archivo no existe" << std::endl;
      leerPly();
  }

}


/*
* Calcular Bounding Box
*Despues 1 glTraslate(bx,by,bz)
*Despues 2 glEscale(.....)
*
*/
