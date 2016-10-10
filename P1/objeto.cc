#include"objeto.h"
#include<iostream>

Objeto::Objeto(){
  modoPintado = 2;
  mode = GL_TRIANGLES;
}
void Objeto::dibujar(){

  glColor3f(0.55,0.33,0.15);

  glEnable(GL_CULL_FACE);

  glEnableClientState(GL_VERTEX_ARRAY);
  glPolygonMode(GL_FRONT_AND_BACK,mode);
  glPointSize(4.0f);
  glVertexPointer(3,GL_FLOAT,0,&triangulos[0]);
  glDrawElements(mode,caras.size(),GL_UNSIGNED_INT,&caras[0]);
  glDisableClientState(GL_VERTEX_ARRAY);



}

void Objeto::cambiarDibujado(int nuevo){ //0 puntos 1 lineas 2 solido 3 ajedrez
  modoPintado = nuevo;

  switch (nuevo) {
    case 0:
      mode = GL_POINTS;
      break;
    case 1:
      mode = GL_LINE_STRIP;
      break;
    default:
      mode = GL_TRIANGLES;
      break;
  }


}


int Objeto::getNumTriangulos(){
  return triangulos.size()/9;
}

void Objeto::insertarVertice(float x,float y,float z){
  triangulos.push_back(x);
  triangulos.push_back(y);
  triangulos.push_back(z);
}

void Objeto::insertarCara(int v1, int v2, int v3){
    caras.push_back(v1);
    caras.push_back(v2);
    caras.push_back(v3);
}
