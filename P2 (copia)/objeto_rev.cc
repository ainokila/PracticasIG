#include "objeto_rev.h"
#include <string>
#include <vector>
#include <math.h>
#include <iostream>

ObjetoRevolucion::ObjetoRevolucion(std::vector<float> puntos,float grados){
  puntosIniciales = puntos;
  generarRevolucion(grados);

}

ObjetoRevolucion::ObjetoRevolucion(std::string file,float grados){
  leerPly();
  generarRevolucion(grados);
}

void ObjetoRevolucion::generarRevolucion(float grados){

  //puntos = puntosIniciales;
  std::vector<float>::iterator inicio = puntosIniciales.begin();
  std::vector<float>::iterator fin = puntosIniciales.end();

  int inicioPuntos = 0;
  int finPuntos = puntosIniciales.size();
  int numVerticesInicio = puntosIniciales.size()/3;
  bool tapaSuperiorBoundin = true;
  bool tapaInferiorBoundin = true;

  float tapaSuperior[3],tapaInferior[3];

  //Si estan en el eje los quitamos si x==0 y z==0
  if(puntosIniciales[0] == 0.0f && puntosIniciales[2] == 0.0f){
    for(int i = 0 ; i < 3; i++){
      inicio++;
    }
    tapaSuperior[0] = tapaSuperior[2] = 0.0f;
    tapaSuperior[1] = puntosIniciales[1];
    inicioPuntos = 3;
    numVerticesInicio--;
    //Hemos guardado el punto y decimos que no genere tapa mediante boundin
    tapaSuperiorBoundin = false;
  }

  //Si estan en el eje los quitamos si x==0 y z==0
  if(puntosIniciales[puntosIniciales.size()-1] == 0.0f && puntosIniciales[puntosIniciales.size()-3] == 0.0f){
    for(int i = 0 ; i < 3; i++){
      fin--;
    }
    tapaInferior[0] = tapaInferior[2] = 0.0f;
    tapaInferior[1] = puntosIniciales[puntosIniciales.size()-2];
    finPuntos -= 3;
    numVerticesInicio--;

    //Hemos guardado el punto y decimos que no genere tapa mediante boundin
    tapaInferiorBoundin = false;
  }

  //Aniado a triangulo los puntos iniciales excepto el primer y ultimo vertice
  puntos.insert(puntos.begin(),inicio,fin);




  //Insertamos los vertices creados por revolucion
  for(float i= grados; i < 360.0f ; i = i+grados){

    float rad = i *( 3.14159265f/180.0f );

    //Genero los puntos del meridiano sin el vertice superior e inferior
    for(int j = inicioPuntos ; j < finPuntos ; j = j+3){
      insertarVertice(puntosIniciales[j]*cos(rad) + sin(rad)*puntosIniciales[j+2],puntosIniciales[j+1],-1*sin(rad)*puntosIniciales[j] + puntosIniciales[j+2]*cos(rad));
    }


    int inicio = getNumVertices() - 2*(numVerticesInicio);
    int fin = getNumVertices() - (numVerticesInicio) ;

    //Genera el cuerpo del objeto
    for(int h = inicio  ; h < fin -1; h++){
        insertarCara(h,h+1,h+numVerticesInicio);
        insertarCara(h+1,h+numVerticesInicio+1,h+numVerticesInicio);
    }

    //Insertamos los vertices de la tapa situados en el eje de coordenadas de y
    insertarVertice(tapaSuperior[0],tapaSuperior[1],tapaSuperior[2]);
    insertarVertice(tapaInferior[0],tapaInferior[1],tapaInferior[2]);

    //Generamos tapa superior

    if(tapaSuperiorBoundin){
      tapaSuperior[1] = bound.getMaxY();
    }

    if(tapaInferiorBoundin){
      tapaInferior[1] = bound.getMinY();
    }

    //ERROR!
    //Tapa superior
    for(int i=0;i<getNumVertices() - numVerticesInicio; i = i +numVerticesInicio ){
      insertarCara(i,i+numVerticesInicio,(puntos.size()/3));
    }
    //Tapa inferior




}



/* ******* PINTA MAAAL *******************
std::vector<float>::iterator inicio = puntosIniciales.begin();
std::vector<float>::iterator fin = puntosIniciales.end();

for(int i = 0 ; i < 3; i++){
  inicio++;
  fin--;
}

//Aniado a triangulo los puntos iniciales excepto el primer y ultimo vertice
puntos.insert(puntos.begin(),inicio,fin);

//Le quitamos el primer y ultimo vertice de los puntos iniciales
int numVerticesInicio = puntosIniciales.size()/3 - 2;


//Insertamos los vertices creados por revolucion
for(float i= grados; i < 360.0f ; i = i+grados){
  float rad = i ;//*( 3.14159265/180.0 );

  //Genero los puntos del meridiano sin el vertice superior e inferior
  for(int j = 3 ; j < puntosIniciales.size()-3; j = j+3){
    insertarVertice(puntosIniciales[j]*cos(rad) + sin(rad)*puntosIniciales[j+2],puntosIniciales[j+1],-1*sin(rad)*puntosIniciales[j] + puntosIniciales[j+2]*cos(rad));
  }

  //Unir aqui con el perfil anterior

  int inicio = getNumVertices() - 2 * numVerticesInicio;
  int fin = getNumVertices()- numVerticesInicio-1;

  for(int h = inicio  ; h < fin ; h++){
      insertarCara(h,h+1,h+numVerticesInicio);
  }



}*/






}
