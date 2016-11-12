#include "base.h"

Base::Base(){

  std::vector<float> aux;
  aux.push_back(0.0f);  aux.push_back(-0.5f);  aux.push_back(0.0f);
  aux.push_back(0.5f);  aux.push_back(-0.5f);  aux.push_back(0.0f);
  aux.push_back(0.5f);  aux.push_back(-0.1f);  aux.push_back(0.0f);
  aux.push_back(0.3f);  aux.push_back(-0.1f);  aux.push_back(0.0f);
  aux.push_back(0.3f);  aux.push_back(0.3f);  aux.push_back(0.0f);
  aux.push_back(0.1f);  aux.push_back(0.3f);  aux.push_back(0.0f);
  aux.push_back(0.1f);  aux.push_back(0.5f);  aux.push_back(0.0f);
  aux.push_back(0.0f);  aux.push_back(0.5f);  aux.push_back(0.0f);

  set(aux ,60.0f,0);
  generarRevolucion();
  generaTapas();
}
