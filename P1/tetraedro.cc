#include "tetraedro.h"
#include<iostream>


Tetraedro::Tetraedro(float baseX,float alturaY,float baseZ){
  //Se crea cubo con las medidas especificadas o si no de 1x1x1

  insertarVertice(0.0f,0.0f,0.0f);//v0
  insertarVertice(100.0f,0.0f,0.0f);//v1
  insertarVertice(50.0f,0.0f,-86.0f);//v2
  insertarVertice(43.0f,43.0f,-43.0f);//v3


  insertarCara(0,1,2);
  insertarCara(0,1,3);
  insertarCara(3,2,0);
  insertarCara(3,1,2);





}
