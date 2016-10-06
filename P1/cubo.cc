#include "cubo.h"
#include<iostream>


Cubo::Cubo(float ladoX ,float ladoY ,float ladoZ){
  //Se crea cubo con las medidas especificadas o si no de 1x1x1

  insertarVertice(0.0f,0.0f,0.0f);
  insertarVertice(100.0f,0.0f,0.0f);
  insertarVertice(0.0f,100.0f,0.0f);

  insertarVertice(100.0f,0.0f,0.0f);
  insertarVertice(100.0f,100.0f,0.0f);
  insertarVertice(0.0f,100.0f,0.0f);

  insertarVertice(100.0f,0.0f,0.0f);
  insertarVertice(100.0f,0.0f,-100.0f);
  insertarVertice(100.0f,100.0f,-100.0f);

  insertarVertice(100.0f,100.0f,-100.0f);
  insertarVertice(100.0f,100.0f,0.0f);
  insertarVertice(100.0f,0.0f,0.0f);

  insertarVertice(0.0f,100.0f,0.0f);
  insertarVertice(100.0f,100.0f,0.0f);
  insertarVertice(0.0f,100.0f,-100.0f);

  insertarVertice(0.0f,100.0f,-100.0f);
  insertarVertice(100.0f,100.0f,0.0f);
  insertarVertice(100.0f,100.0f,-100.0f);

  insertarVertice(0.0f,0.0f,0.0f);
  insertarVertice(0.0f,100.0f,0.0f);
  insertarVertice(0.0f,0.0f,-100.0f);


  insertarVertice(0.0f,100.0f,-100.0f);
  insertarVertice(0.0f,0.0f,-100.0f);
  insertarVertice(0.0f,100.0f,0.0f);

  insertarVertice(100.0f,100.0f,0.0f);
  insertarVertice(0.0f,0.0f,-100.0f);
  insertarVertice(0.0f,100.0f,-100.0f);



  insertarVertice(100.0f,100.0f,-100.0f);
  insertarVertice(100.0f,0.0f,-100.0f);
  insertarVertice(0.0f,0.0f,-100.0f);

  insertarVertice(100.0f,0.0f,0.0f);
  insertarVertice(0.0f,0.0f,0.0f);
  insertarVertice(100.0f,0.0f,-100.0f);

  insertarVertice(0.0f,0.0f,0.0f);
  insertarVertice(0.0f,0.0f,-100.0f);
  insertarVertice(100.0f,0.0f,-100.0f);
























  std::cout << triangulos.size() << std::endl;


}
