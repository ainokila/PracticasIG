#include "cubo.h"
#include<iostream>


Cubo::Cubo(float ladoX ,float ladoY ,float ladoZ){
  //Se crea cubo con las medidas especificadas o si no de 1x1x1


  insertarVertice(ladoX*0.0f,ladoY*0.0f,ladoZ*0.0f);
  insertarVertice(ladoX*100.0f,ladoY*0.0f,ladoZ*0.0f);
  insertarVertice(ladoX*0.0f,ladoY*100.0f,ladoZ*0.0f);

  insertarVertice(ladoX*100.0f,ladoY*0.0f,ladoZ*0.0f);
  insertarVertice(ladoX*100.0f,ladoY*100.0f,ladoZ*0.0f);
  insertarVertice(ladoX*0.0f,ladoY*100.0f,ladoZ*0.0f);

  insertarVertice(ladoX*100.0f,ladoY*0.0f,ladoZ*0.0f);
  insertarVertice(ladoX*100.0f,ladoY*0.0f,ladoZ*-100.0f);
  insertarVertice(ladoX*100.0f,ladoY*100.0f,ladoZ*-100.0f);

  insertarVertice(ladoX*100.0f,ladoY*100.0f,ladoZ*-100.0f);
  insertarVertice(ladoX*100.0f,ladoY*100.0f,ladoZ*0.0f);
  insertarVertice(ladoX*100.0f,ladoY*0.0f,ladoZ*0.0f);

  insertarVertice(ladoX*0.0f,ladoY*100.0f,ladoZ*0.0f);
  insertarVertice(ladoX*100.0f,ladoY*100.0f,ladoZ*0.0f);
  insertarVertice(ladoX*0.0f,ladoY*100.0f,ladoZ*-100.0f);

  insertarVertice(ladoX*0.0f,ladoY*100.0f,ladoZ*-100.0f);
  insertarVertice(ladoX*100.0f,ladoY*100.0f,ladoZ*0.0f);
  insertarVertice(ladoX*100.0f,ladoY*100.0f,ladoZ*-100.0f);

  insertarVertice(ladoX*0.0f,ladoY*0.0f,ladoZ*0.0f);
  insertarVertice(ladoX*0.0f,ladoY*100.0f,ladoZ*0.0f);
  insertarVertice(ladoX*0.0f,ladoY*0.0f,ladoZ*-100.0f);


  insertarVertice(ladoX*0.0f,ladoY*100.0f,ladoZ*-100.0f);
  insertarVertice(ladoX*0.0f,ladoY*0.0f,ladoZ*-100.0f);
  insertarVertice(ladoX*0.0f,ladoY*100.0f,ladoZ*0.0f);

  insertarVertice(ladoX*0.0f,ladoY*100.0f,ladoZ*-100.0f);
  insertarVertice(ladoX*100.0f,ladoY*100.0f,ladoZ*-100.0f);
  insertarVertice(ladoX*0.0f,ladoY*0.0f,ladoZ*-100.0f);

  insertarVertice(ladoX*100.0f,ladoY*100.0f,ladoZ*-100.0f);
  insertarVertice(ladoX*100.0f,ladoY*0.0f,ladoZ*-100.0f);
  insertarVertice(ladoX*0.0f,ladoY*0.0f,ladoZ*-100.0f);

  insertarVertice(ladoX*100.0f,ladoY*0.0f,ladoZ*0.0f);
  insertarVertice(ladoX*0.0f,ladoY*0.0f,ladoZ*0.0f);
  insertarVertice(ladoX*100.0f,ladoY*0.0f,ladoZ*-100.0f);

  insertarVertice(ladoX*0.0f,ladoY*0.0f,ladoZ*0.0f);
  insertarVertice(ladoX*0.0f,ladoY*0.0f,ladoZ*-100.0f);
  insertarVertice(ladoX*100.0f,ladoY*0.0f,ladoZ*-100.0f);

}
