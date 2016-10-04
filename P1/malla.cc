#include<malla.h>
#include<iostream>


void Malla::dibujar(){
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3,GL_FLOAT,0,triangulos.front());
  


}
