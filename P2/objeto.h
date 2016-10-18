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
    void insertarCara(int v1, int v2, int v3);
    inline void setTriangulos(std::vector<float> aux){triangulos = aux;};
    inline void setCaras(std::vector<int> aux){caras = aux;};
    void ampliar();
    void reducir();


  protected:

    std::vector<float> triangulos;
    std::vector<int> caras;
    int modoPintado; //0 puntos 1 lineas 2 solido 3 ajedrez
    GLenum modePolygon;
};

#endif
