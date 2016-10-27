#ifndef _BOUND_
#define _BOUND_
#include <vector>
#include"vertice.h"

class BoundingBox{
public:

  BoundingBox();
  void nuevaX(float x);
  void nuevaY(float y);
  void nuevaZ(float z);
  void calcularBoundingBox(std::vector<Vertice> v);
  void imprimeDatos();


private:
  float x_min,x_max,y_min,y_max,z_min,z_max;
};




#endif
