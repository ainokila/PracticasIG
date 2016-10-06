#include"objeto.h"
#include<iostream>

Objeto::Objeto(){

}
void Objeto::dibujar(){

  glEnableClientState(GL_VERTEX_ARRAY);

  glVertexPointer(3,GL_FLOAT,0,&triangulos[0]);
  glDrawArrays( GL_TRIANGLES,0,triangulos.size()) ; //DUDA EN EL 3 O 0

  glDisableClientState(GL_VERTEX_ARRAY);

}

void Objeto::cambiarDibujado(int nuevo){
  modoPintado = nuevo;
}


int Objeto::getNumTriangulos(){
  return triangulos.size()/9;
}

void Objeto::insertarVertice(float x,float y,float z){
  triangulos.push_back(x);
  triangulos.push_back(y);
  triangulos.push_back(z);
}
