#ifndef _OBJREV_
#define _OBJREV_

#include "objeto.h"
#include <string>

class ObjetoRevolucion : public Objeto{

public:
  ObjetoRevolucion(std::vector<float> puntos,float grados=30.0f);
  ObjetoRevolucion(std::string file,float grados=30.0f);
  void generarRevolucion(float grados);

private:
  std::vector<float> puntosIniciales;

};


#endif
