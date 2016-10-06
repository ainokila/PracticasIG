#ifndef _MALLA_H
#define _MALLA_H
#include<vector>
#include <GL/gl.h>

typedef GLfloat Vertice[3];


class Objeto{


  public:

    Objeto();
    void dibujar();
    int getNumTriangulos();
    void insertarVertice(float x,float y,float z);

  protected:

    std::vector<float> triangulos;
};

#endif
