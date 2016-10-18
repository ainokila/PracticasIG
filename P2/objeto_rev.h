#ifndef _OBJREV_
#define _OBJREV_

#include "objeto.h"
#include <string>

class ObjetoRevolucion : public Objeto{

public:
  ObjetoRevolucion(std::vector<float> puntos);

  ObjetoRevolucion(std::string file);

};


#endif
