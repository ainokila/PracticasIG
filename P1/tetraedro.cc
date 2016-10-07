#include "tetraedro.h"
#include<iostream>


Tetraedro::Tetraedro(float baseX,float alturaY,float baseZ){
  //Se crea cubo con las medidas especificadas o si no de 1x1x1

  insertarVertice(0.0f,0.0f,0.0f);
  insertarVertice(100.0f,0.0f,0.0f);
  insertarVertice(50.0f,0.0f,-86.0f);

  insertarVertice(0.0f,0.0f,0.0f);
  insertarVertice(100.0f,0.0f,0.0f);
  insertarVertice(43.0f,43.0f,-43.0f);

  insertarVertice(43.0f,43.0f,-43.0f);
  insertarVertice(50.0f,0.0f,-86.0f);
  insertarVertice(0.0f,0.0f,0.0f);

  insertarVertice(43.0f,43.0f,-43.0f);
  insertarVertice(100.0f,0.0f,0.0f);
  insertarVertice(50.0f,0.0f,-86.0f);



}
