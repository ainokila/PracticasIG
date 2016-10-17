#include"objeto.h"
#include<iostream>

Objeto::Objeto(){

  modoPintado = 2;
  mode = GL_TRIANGLES;
  modePolygon = GL_FILL;
}
void Objeto::dibujar(){

  glColor3f(0.35,0.33,0.15);
  glPointSize(4.0f);
  glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3,GL_FLOAT,0,&triangulos[0]);
  glEnable(GL_CULL_FACE);
  glPolygonMode(GL_FRONT_AND_BACK,modePolygon);

  glDrawElements(mode,caras.size(),GL_UNSIGNED_INT,&caras[0]);
  glDisableClientState(GL_VERTEX_ARRAY);


}

void Objeto::cambiarDibujado(int nuevo){ //0 puntos 1 lineas 2 solido 3 ajedrez
  modoPintado = nuevo;

  switch (nuevo) {
    case 0:
      mode = GL_POINTS;
      modePolygon = GL_FILL;
      break;
    case 1:
      mode = GL_LINE_STRIP;
      modePolygon = GL_LINES;
      break;
    default:
      mode = GL_TRIANGLES;
      modePolygon = GL_FILL;

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

void Objeto::ampliar(){
  for(int i = 0 ; i < triangulos.size() ; i++){
    triangulos[i]*=1.25;
  }
}

void Objeto::reducir(){
  for(int i = 0 ; i < triangulos.size() ; i++){
    triangulos[i]/=1.25;
  }

}
