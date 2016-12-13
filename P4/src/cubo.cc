#include "cubo.h"
#include<iostream>


Cubo::Cubo(float ladoX ,float ladoY ,float ladoZ){

  insertarVertice(-0.5f*ladoX,-0.5f*ladoY,0.5f*ladoZ);
  insertarVertice(0.5f*ladoX,-0.5f*ladoY,0.5f*ladoZ);
  insertarVertice(-0.5f*ladoX,0.5f*ladoY,0.5f*ladoZ);
  insertarVertice(0.5f*ladoX,0.5f*ladoY,0.5f*ladoZ);
  insertarVertice(-0.5f*ladoX,-0.5f*ladoY,-0.5f*ladoZ);
  insertarVertice(0.5f*ladoX,-0.5f*ladoY,-0.5f*ladoZ);
  insertarVertice(-0.5f*ladoX,0.5f*ladoY,-0.5f*ladoZ);
  insertarVertice(0.5f*ladoX,0.5f*ladoY,-0.5f*ladoZ);

  insertarCara(0,1,2);
  insertarCara(1,3,2);
  insertarCara(2,3,7);
  insertarCara(2,7,6);
  insertarCara(1,7,3);
  insertarCara(1,5,7);
  insertarCara(6,7,4);
  insertarCara(7,5,4);
  insertarCara(0,4,1);
  insertarCara(1,4,5);
  insertarCara(2,6,4);
  insertarCara(0,2,4);

  calcularNormales();


}
