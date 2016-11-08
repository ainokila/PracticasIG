#ifndef _OBJREV_
#define _OBJREV_

#include "objeto.h"
#include <string>

class ObjetoRevolucion : public Objeto{

public:
  ObjetoRevolucion(float gr);
  ObjetoRevolucion(std::vector<float> puntos,float gr=15.0f);
  ObjetoRevolucion(std::string file,float gr=15.0f);
  void generarRevolucion();
  void leerPly();
  void generaTapas();
  void quitaTapas();

private:
  std::vector<float> puntosIniciales;
  float grados;
  int carasTapas;
  int numVerticesInicio;
  bool tapas;
};


#endif
