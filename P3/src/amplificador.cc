#include "amplificador.h"

Amplificador::Amplificador(){

  std::vector<float> aux;
  aux.push_back(0.0f);  aux.push_back(0.0f);  aux.push_back(0.0f);
  aux.push_back(0.5f);  aux.push_back(-0.5f);  aux.push_back(0.0f);
  aux.push_back(0.25f);  aux.push_back(0.5f);  aux.push_back(0.0f);
  aux.push_back(0.0f);  aux.push_back(0.5f);  aux.push_back(0.0f);

  set(aux ,10.0f,0);
  generarRevolucion();
  generaTapas();
}
