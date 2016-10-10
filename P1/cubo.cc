#include "cubo.h"
#include<iostream>


Cubo::Cubo(float ladoX ,float ladoY ,float ladoZ){
  //Se crea cubo con las medidas especificadas o si no de 1x1x1
  std::cout << "Cubo creado" << std::endl;

  //Pared frontal
/*
  insertarVertice(ladoX*0.0f,ladoY*0.0f,ladoZ*0.0f); // 0
  insertarVertice(ladoX*100.0f,ladoY*0.0f,ladoZ*0.0f); // 1
  insertarVertice(ladoX*0.0f,ladoY*100.0f,ladoZ*0.0f); // 2

  insertarVertice(ladoX*100.0f,ladoY*0.0f,ladoZ*0.0f); //1
  insertarVertice(ladoX*100.0f,ladoY*100.0f,ladoZ*0.0f);//3
  insertarVertice(ladoX*0.0f,ladoY*100.0f,ladoZ*0.0f);//2


  //Lateral Derecho

  insertarVertice(ladoX*100.0f,ladoY*100.0f,ladoZ*-100.0f); //4
  insertarVertice(ladoX*100.0f,ladoY*0.0f,ladoZ*0.0f);//1
  insertarVertice(ladoX*100.0f,ladoY*0.0f,ladoZ*-100.0f);//5


  insertarVertice(ladoX*100.0f,ladoY*100.0f,ladoZ*-100.0f);//4
  insertarVertice(ladoX*100.0f,ladoY*100.0f,ladoZ*0.0f);//3
  insertarVertice(ladoX*100.0f,ladoY*0.0f,ladoZ*0.0f);//1

  //Tapa cubo

  insertarVertice(ladoX*0.0f,ladoY*100.0f,ladoZ*0.0f); //2
  insertarVertice(ladoX*100.0f,ladoY*100.0f,ladoZ*0.0f); //6
  insertarVertice(ladoX*0.0f,ladoY*100.0f,ladoZ*-100.0f); //7

  insertarVertice(ladoX*0.0f,ladoY*100.0f,ladoZ*-100.0f); //7
  insertarVertice(ladoX*100.0f,ladoY*100.0f,ladoZ*0.0f);//6
  insertarVertice(ladoX*100.0f,ladoY*100.0f,ladoZ*-100.0f); //4

  //Lateral izquierdo

  insertarVertice(ladoX*0.0f,ladoY*0.0f,ladoZ*0.0f); //0
  insertarVertice(ladoX*0.0f,ladoY*100.0f,ladoZ*0.0f);//2
  insertarVertice(ladoX*0.0f,ladoY*0.0f,ladoZ*-100.0f);//8


  insertarVertice(ladoX*0.0f,ladoY*100.0f,ladoZ*-100.0f); //7
  insertarVertice(ladoX*0.0f,ladoY*0.0f,ladoZ*-100.0f);//8
  insertarVertice(ladoX*0.0f,ladoY*100.0f,ladoZ*0.0f); //2


  //Frontal del fondo

  insertarVertice(ladoX*0.0f,ladoY*100.0f,ladoZ*-100.0f); //7
  insertarVertice(ladoX*100.0f,ladoY*100.0f,ladoZ*-100.0f); //4
  insertarVertice(ladoX*0.0f,ladoY*0.0f,ladoZ*-100.0f);//8

  insertarVertice(ladoX*100.0f,ladoY*100.0f,ladoZ*-100.0f);//4
  insertarVertice(ladoX*100.0f,ladoY*0.0f,ladoZ*-100.0f);//5
  insertarVertice(ladoX*0.0f,ladoY*0.0f,ladoZ*-100.0f);//8

  //Base

  insertarVertice(ladoX*100.0f,ladoY*0.0f,ladoZ*0.0f); //1
  insertarVertice(ladoX*0.0f,ladoY*0.0f,ladoZ*0.0f);//0
  insertarVertice(ladoX*100.0f,ladoY*0.0f,ladoZ*-100.0f);//5

  insertarVertice(ladoX*0.0f,ladoY*0.0f,ladoZ*0.0f);//0
  insertarVertice(ladoX*0.0f,ladoY*0.0f,ladoZ*-100.0f);//8
  insertarVertice(ladoX*100.0f,ladoY*0.0f,ladoZ*-100.0f);//5*/

  insertarVertice(ladoX*0.0f,ladoY*0.0f,ladoZ*0.0f); // 0
  insertarVertice(ladoX*100.0f,ladoY*0.0f,ladoZ*0.0f); // 1
  insertarVertice(ladoX*0.0f,ladoY*100.0f,ladoZ*0.0f); // 2
  insertarVertice(ladoX*100.0f,ladoY*100.0f,ladoZ*0.0f);//3
  insertarVertice(ladoX*100.0f,ladoY*100.0f,ladoZ*-100.0f);//4
  insertarVertice(ladoX*100.0f,ladoY*0.0f,ladoZ*-100.0f);//5
  insertarVertice(ladoX*100.0f,ladoY*100.0f,ladoZ*0.0f);//6
  insertarVertice(ladoX*0.0f,ladoY*100.0f,ladoZ*-100.0f); //7
  insertarVertice(ladoX*0.0f,ladoY*0.0f,ladoZ*-100.0f);//8

  insertarCara(0,1,2);
  insertarCara(1,3,2);
  insertarCara(4,1,5);
  insertarCara(4,3,1);
  insertarCara(2,6,7);
  insertarCara(7,6,4);
  insertarCara(0,2,8);
  insertarCara(7,8,2);
  insertarCara(7,4,8);
  insertarCara(4,5,8);
  insertarCara(1,0,5);
  insertarCara(0,8,5);




}
