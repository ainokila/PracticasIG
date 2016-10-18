#include "objeto_rev.h"
#include <string>
#include <vector>

ObjetoRevolucion::ObjetoRevolucion(std::vector<float> puntos){
  puntosIniciales = puntos;

}
ObjetoRevolucion::ObjetoRevolucion(std::string file){
  leerPly(file);
}
