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
    void cambiarDibujado(int nuevo);

  protected:

    std::vector<float> triangulos;
    int modoPintado = 0; //0 puntos 1 lineas 2 solido 3 ajedrez
};

#endif
