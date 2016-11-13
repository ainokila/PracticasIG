#include "cilindro.h"

Cilindro::Cilindro(){

  std::vector<float> aux;
  aux.push_back(0.0f);  aux.push_back(-0.5f);  aux.push_back(0.0f);
  aux.push_back(0.5f);  aux.push_back(-0.5f);  aux.push_back(0.0f);
  aux.push_back(0.5f);  aux.push_back(0.5f);  aux.push_back(0.0f);
  aux.push_back(0.0f);  aux.push_back(0.5f);  aux.push_back(0.0f);

  set(aux,36.0f,0);
  generarRevolucion();
  generaTapas();

}
