#ifndef _MALLA_H
#define _MALLA_H
#include<vector>
#include <GL/gl.h>
#include "file_ply_stl.h"
#include "bounding_box.h"
#include "vertice.h"

class Objeto{


  public:
    struct Cara{
      GLint v1;
      GLint v2;
      GLint v3;
    };
    Objeto();
    void dibujar();
    int getNumPuntos();

    inline int getNumVertices(){return vertices.size();};
    inline int getNumCaras(){return caras.size()/3;};

    void insertarVertice(float x,float y,float z);
    void cambiarDibujado(int nuevo);
    void insertarCara(int v1, int v2, int v3);

    inline void setVertices(std::vector<Vertice> aux){vertices = aux;};
    inline void setCaras(std::vector<Cara> aux){caras = aux;};
    void leerPly();


    void ampliar();
    void reducir();


  protected:

    std::vector<Vertice> vertices;
    std::vector<Cara> caras;
    int modoPintado; //0 puntos 1 lineas 2 solido 3 ajedrez
    GLenum modePolygon;
    BoundingBox bound;
};

#endif
