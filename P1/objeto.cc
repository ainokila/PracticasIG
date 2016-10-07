#include"objeto.h"
#include<iostream>

Objeto::Objeto(){

}
void Objeto::dibujar(){

  glEnableClientState(GL_VERTEX_ARRAY);

  glVertexPointer(3,GL_FLOAT,0,&triangulos[0]);
  glDrawArrays( mode,0,triangulos.size());

  glDisableClientState(GL_VERTEX_ARRAY);

}

void Objeto::cambiarDibujado(int nuevo){ //0 puntos 1 lineas 2 solido 3 ajedrez
  modoPintado = nuevo;

  switch (nuevo) {
    case 0:
      mode = GL_POINTS;
      break;
    case 1:
      mode = GL_LINES;
      break;
    case 2:
      mode = GL_TRIANGLES;
    case 3:
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
