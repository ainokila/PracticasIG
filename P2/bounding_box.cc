#include "bounding_box.h"
#include <iostream>

BoundingBox::BoundingBox(){
  x_min=x_max=y_min=y_max=z_min=z_max=0.0f;
}
void BoundingBox::nuevaX(float x){
  if(x >= x_max){
    x_max = x;
  }else if(x <= x_min){
    x_min = x;
  }
}
void BoundingBox::nuevaY(float y){
  if(y >= y_max){
    y_max = y;
  }else if(y <= y_min){
    y_min = y;
  }
}
void BoundingBox::nuevaZ(float z){
  if(z >= z_max){
    z_max = z;
  }else if(z <= z_min){
    z_min = z;
  }
}

void BoundingBox::calcularBoundingBox(std::vector<Vertice> v){
  x_min=x_max=y_min=y_max=z_min=z_max=0.0f;
  for(int i = 0 ; i < v.size() ; i++){
    nuevaX(v[i].x);
    nuevaY(v[i].y);
    nuevaZ(v[i].z);
  }
}

void BoundingBox::imprimeDatos(){
  std::cout << x_min << "-" << x_max << std::endl;
  std::cout << y_min << "-" << y_max << std::endl;
  std::cout << z_min << "-" << z_max << std::endl;

}
