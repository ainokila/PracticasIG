#ifndef _BOUND_
#define _BOUND_
#include <vector>

class BoundingBox{
public:

  BoundingBox();
  void nuevaX(float x);
  void nuevaY(float y);
  void nuevaZ(float z);
  void calcularBoundingBox(std::vector<float> v);
  void imprimeDatos();
  inline float getMinX(){return x_min;};
  inline float getMaxX(){return x_max;};
  inline float getMinY(){return y_min;};
  inline float getMaxY(){return y_max;};
  inline float getMinZ(){return z_min;};
  inline float getMaxZ(){return z_max;};
  inline float diffX(){x_max-x_min;};
  inline float diffY(){y_max-y_min;};
  inline float diffZ(){z_max-z_min;};



private:
  float x_min,x_max,y_min,y_max,z_min,z_max;
};




#endif
