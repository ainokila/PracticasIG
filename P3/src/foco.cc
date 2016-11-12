#include "foco.h"

Foco::Foco(){

  std::vector<float> aux;
  aux.push_back(0.0f);  aux.push_back(-0.5f);  aux.push_back(0.0f);
  aux.push_back(0.5f);  aux.push_back(-0.5f);  aux.push_back(0.0f);
  aux.push_back(0.2f);  aux.push_back(0.1f);  aux.push_back(0.0f);
  aux.push_back(0.2f);  aux.push_back(0.4f);  aux.push_back(0.0f);
  aux.push_back(0.1f);  aux.push_back(0.4f);  aux.push_back(0.0f);
  aux.push_back(0.1f);  aux.push_back(0.5f);  aux.push_back(0.0f);
  aux.push_back(0.0f);  aux.push_back(0.5f);  aux.push_back(0.0f);

  set(aux,10.0f,0);
  generarRevolucion();
  generaTapas();
}
