#ifndef _MALLA_H
#define _MALLA_H
#include<vector>
#include <GL/gl.h>
#include "file_ply_stl.h"
#include "bounding_box.h"


typedef GLfloat Vertice[3];


class Objeto{


  public:

    Objeto();
    void dibujar();

    inline int getNumVertices(){return puntos.size()/3;};
    inline int getNumCaras(){return caras.size()/3;};

    void insertarVertice(float x,float y,float z);
    void cambiarDibujado(int nuevo);
    void insertarCara(int v1, int v2, int v3);

    inline void setPuntos(std::vector<float> aux){puntos = aux;};
    inline void setCaras(std::vector<int> aux){caras = aux;};
    void leerPly();


    void ampliar();
    void reducir();

    void calcularNormalesPuntos();


  protected:

    std::vector<float> puntos;
    std::vector<float> normalesPuntos;
    std::vector<float> auxiliarNormal;
    std::vector<int> caras;
    std::vector<float> normalesCaras;
    int modoPintado; //0 puntos 1 lineas 2 solido 3 ajedrez
    GLenum modePolygon;
    BoundingBox bound;
};

#endif
