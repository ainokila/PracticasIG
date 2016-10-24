#include "objeto_rev.h"
#include <string>
#include <vector>
#include <math.h>

ObjetoRevolucion::ObjetoRevolucion(std::vector<float> puntos,float grados){
  puntosIniciales = puntos;
  generarRevolucion(grados);

}

ObjetoRevolucion::ObjetoRevolucion(std::string file,float grados){
  leerPly();
  generarRevolucion(grados);
}

void ObjetoRevolucion::generarRevolucion(float grados){

  triangulos = puntosIniciales;
  std::vector<float>::iterator inicio = puntosIniciales.begin();
  std::vector<float>::iterator fin = puntosIniciales.end();

  for(int i = 0 ; i < 3; i++){
    inicio++;
    fin--;
  }

  //Aniado a triangulo los puntos iniciales excepto el primer y ultimo vertice
  triangulos.insert(triangulos.begin(),inicio,fin);

  //Insertamos los vertices creados por revolucion
  for(float i= grados; i < 360.0f ; i = i+grados){

    //Genero los puntos del meridiano
    for(int j = 3 ; j < puntosIniciales.size()-3; j = j+3){
      insertarVertice(puntosIniciales[j]*cos(i),puntosIniciales[j+1],puntosIniciales[j+2]*sin(i));
    }

    //Unir aqui con el perfil anterior
    int tamanio = puntosIniciales.size() - 2;

    for(int h = triangulos.size()-2*tamanio ; h < triangulos.size()-tamanio-1 ; h++){
        insertarCara(h,h+1,h+tamanio);
    }

    for(int h = triangulos.size(); h > triangulos.size()-tamanio ; h-- ){
        insertarCara(h,h-1,h-tamanio);
    }


  }


}
