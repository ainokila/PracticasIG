#include "objeto_rev.h"
#include <string>
#include <vector>
#include <math.h>
#include <iostream>

ObjetoRevolucion::ObjetoRevolucion(std::vector<Vertice> puntos,float grados){
  puntosIniciales = puntos;
  generarRevolucion(grados);

}

ObjetoRevolucion::ObjetoRevolucion(std::string file,float grados){
  leerPly();
  generarRevolucion(grados);
}

void ObjetoRevolucion::generarRevolucion(float grados){

  //puntos = puntosIniciales;
  std::vector<Vertice>::iterator inicio = puntosIniciales.begin();
  std::vector<Vertice>::iterator fin = puntosIniciales.end();

  int inicioPuntos = 0;
  int finPuntos = puntosIniciales.size();

  //Si estan en el eje los quitamos
  if(puntosIniciales[0].x == 0.0f && puntosIniciales[0].z == 0.0f){
    for(int i = 0 ; i < 3; i++){
      inicio++;
    }
    inicioPuntos = 3;
  }

  //Si estan en el eje los quitamos
  if(puntosIniciales[puntosIniciales.size()-1].x == 0.0f && puntosIniciales[puntosIniciales.size()-1].z == 0.0f){
    for(int i = 0 ; i < 3; i++){
      fin--;
    }
    finPuntos -= 3;
  }

  //Aniado a triangulo los puntos iniciales excepto el primer y ultimo vertice
  vertices.insert(vertices.begin(),inicio,fin);

  int numVerticesInicio = puntosIniciales.size()/3;


  //Insertamos los vertices creados por revolucion
  for(float i= grados; i < 360.0f ; i = i+grados){

    float rad = i *( 3.14159265f/180.0f );

    //Genero los puntos del meridiano sin el vertice superior e inferior
    for(int j = inicioPuntos ; j < finPuntos ; j++){
      insertarVertice(puntosIniciales[j].x*cos(rad) + sin(rad)*puntosIniciales[j].z,puntosIniciales[j].y,-1*sin(rad)*puntosIniciales[j].x + puntosIniciales[j].z*cos(rad));
      //insertarVertice(puntosIniciales[j]*cos(rad),puntosIniciales[j+1],puntosIniciales[j+2]*sin(rad));
    }


    int inicio = getNumVertices() - 2*(puntosIniciales.size())/3 ;
    int fin = getNumVertices() - (puntosIniciales.size())/3 ;

    for(int h = inicio  ; h < fin - 1 ; h++){
        insertarCara(h,h+1,h+numVerticesInicio);
    }

    for(int h = (puntosIniciales.size())/3 ; h > fin +1 ; h--){
        insertarCara(h,h-1,h-numVerticesInicio);
    }
}



/* ******* PINTA MAAAL *******************
std::vector<float>::iterator inicio = puntosIniciales.begin();
std::vector<float>::iterator fin = puntosIniciales.end();

for(int i = 0 ; i < 3; i++){
  inicio++;
  fin--;
}

//Aniado a triangulo los puntos iniciales excepto el primer y ultimo vertice
puntos.insert(puntos.begin(),inicio,fin);

//Le quitamos el primer y ultimo vertice de los puntos iniciales
int numVerticesInicio = puntosIniciales.size()/3 - 2;


//Insertamos los vertices creados por revolucion
for(float i= grados; i < 360.0f ; i = i+grados){
  float rad = i ;//*( 3.14159265/180.0 );

  //Genero los puntos del meridiano sin el vertice superior e inferior
  for(int j = 3 ; j < puntosIniciales.size()-3; j = j+3){
    insertarVertice(puntosIniciales[j]*cos(rad) + sin(rad)*puntosIniciales[j+2],puntosIniciales[j+1],-1*sin(rad)*puntosIniciales[j] + puntosIniciales[j+2]*cos(rad));
  }

  //Unir aqui con el perfil anterior

  int inicio = getNumVertices() - 2 * numVerticesInicio;
  int fin = getNumVertices()- numVerticesInicio-1;

  for(int h = inicio  ; h < fin ; h++){
      insertarCara(h,h+1,h+numVerticesInicio);
  }



}*/






}
