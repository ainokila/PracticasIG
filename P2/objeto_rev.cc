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
  //triangulos = puntosIniciales;

  for(float i= 0.0f ; i < 360.0f ; i = i+grados){
    for(int j = 3 ; j < puntosIniciales.size()-3; j = j+3){
      insertarVertice(puntosIniciales[j]*cos(i),puntosIniciales[j+1],puntosIniciales[j+2]*sin(i));
    }
  }

}
