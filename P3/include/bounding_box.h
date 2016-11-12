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
  inline float ladoX(){x_max-x_min;};
  inline float ladoY(){y_max-y_min;};
  inline float ladoZ(){z_max-z_min;};
  inline float centroX(){(x_max-x_min)/2.0f;};
  inline float centroY(){(y_max-y_min)/2.0f;};
  inline float centroZ(){(z_max-z_min)/2.0f;};



private:
  float x_min,x_max,y_min,y_max,z_min,z_max;
};




#endif
