#include "objeto_rev.h"
#include <string>
#include <vector>
#include <math.h>

ObjetoRevolucion::ObjetoRevolucion(std::vector<float> puntos,float grados){
  puntosIniciales = puntos;
  generarRevolucion(grados);

}

ObjetoRevolucion::ObjetoRevolucion(std::string file,float grados){
  leerPly();
  generarRevolucion(grados);
}

void ObjetoRevolucion::generarRevolucion(float grados){

  //triangulos = puntosIniciales;
  std::vector<float>::iterator inicio = puntosIniciales.begin();
  std::vector<float>::iterator fin = puntosIniciales.end();

  for(int i = 0 ; i < 3; i++){
    inicio++;
    fin--;
  }

  //Aniado a triangulo los puntos iniciales excepto el primer y ultimo vertice
  triangulos.insert(triangulos.begin(),inicio,fin);

  //Le quitamos el primer y ultimo vertice de los puntos iniciales
  int numVerticesInicio = puntosIniciales.size()/3 - 2;


  //Insertamos los vertices creados por revolucion
  for(float i= grados; i < 360.0f ; i = i+grados){

    //Genero los puntos del meridiano sin el vertice superior e inferior
    for(int j = 3 ; j < puntosIniciales.size()-3; j = j+3){
      insertarVertice(puntosIniciales[j]*cos(i) + sin(i)*puntosIniciales[j+2],puntosIniciales[j+1],-1*sin(i)*puntosIniciales[j] + puntosIniciales[j+2]*cos(i));
    }

    //Unir aqui con el perfil anterior

    int inicio = getNumVertices() - 2 * numVerticesInicio;
    int fin = getNumVertices()- numVerticesInicio-1;

    for(int h = inicio  ; h < fin ; h++){
        insertarCara(h,h+1,h+numVerticesInicio);
    }


    for(int h = getNumVertices()-1 ; h > getNumVertices()-numVerticesInicio+1 ; h-- ){
        insertarCara(h,h-1,h-numVerticesInicio);
    }


  }


}
