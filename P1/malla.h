#ifndef _MALLA_H
#define _MALLA_H
#include<vector>
#include <GL/gl.h>

typedef struct{
  GLfloat v1;
  GLfloat v2;
  GLfloat v3;
}Punto;

class Malla{

  public:
    void dibujar();

  private:
    
    unsigned long totalTriangulos;
    std::vector<Punto> triangulos;


};

#endif
