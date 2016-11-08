#include "objeto_rev.h"
#include <string>
#include <vector>
#include <math.h>
#include <iostream>
#include <unistd.h>


ObjetoRevolucion::ObjetoRevolucion(float gr){
  grados = gr;
  carasTapas=0;

}
ObjetoRevolucion::ObjetoRevolucion(std::vector<float> puntos,float gr){
  puntosIniciales = puntos;
  grados = gr;
  generarRevolucion();
  carasTapas=0;

}

ObjetoRevolucion::ObjetoRevolucion(std::string file,float gr){
  grados = gr;
  leerPly();
  generarRevolucion();
  carasTapas=0;
}

void ObjetoRevolucion::generarRevolucion(){

  //puntos = puntosIniciales;
  std::vector<float>::iterator inicio = puntosIniciales.begin();
  std::vector<float>::iterator fin = puntosIniciales.end();

  int inicioPuntos = 0;
  int finPuntos = puntosIniciales.size();
  numVerticesInicio = puntosIniciales.size()/3;
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
  for(float i= 0.0f; i < 360.0f ; i = i+grados){

    float rad = i *( 3.14159265f/180.0f );

    //Genero los puntos del meridiano sin el vertice superior e inferior
    for(int j = inicioPuntos ; j < finPuntos ; j = j+3){
      insertarVertice(puntosIniciales[j]*cos(rad) + sin(rad)*puntosIniciales[j+2],puntosIniciales[j+1],-1*sin(rad)*puntosIniciales[j] + puntosIniciales[j+2]*cos(rad));
    }


    int inicio = getNumVertices() - 2*(numVerticesInicio);
    int fin = getNumVertices() - (numVerticesInicio) ;

    //Genera el cuerpo del objeto
    for(int h = inicio  ; h < fin -1; h++){
        insertarCara(h,h+numVerticesInicio,h+1);
        insertarCara(h+1,h+numVerticesInicio,h+numVerticesInicio+1);
    }


  }

   //UNO EL PRINCIPIO CON EL FINAL
   for(int h = getNumVertices() - numVerticesInicio   ; h < getNumVertices()-1; h++){
        insertarCara((h)%getNumVertices(),(h+numVerticesInicio)%getNumVertices(),(h+1)%getNumVertices());
        insertarCara((h+1)%getNumVertices(),(h+numVerticesInicio)%getNumVertices(),(h+numVerticesInicio+1)%getNumVertices());
    }

  //UNIR AQUI EL INICIO CON EL FINAL


  bound.calcularBoundingBox(puntos);

  //Cerrar el bucle !

  //Generamos tapa superior

  if(tapaSuperiorBoundin){
      tapaSuperior[1] = bound.getMaxY();
      std::cout << "Eje superior " << tapaSuperior[0] << " " << tapaSuperior[1] << " " << tapaSuperior[2] << std::endl;
  }

  if(tapaInferiorBoundin){
      tapaInferior[1] = bound.getMinY();
      std::cout << "Eje inferior " << tapaInferior[0] << " " << tapaInferior[1] << " " << tapaInferior[2] << std::endl;
  }

      //Insertamos los vertices de la tapa situados en el eje de coordenadas de y
  insertarVertice(tapaSuperior[0],tapaSuperior[1],tapaSuperior[2]);
  insertarVertice(tapaInferior[0],tapaInferior[1],tapaInferior[2]);

  //for(int i= 0 ; i < puntos.size();i++){
      //std::cout << puntos[i] << " " ;
  //}
  //generaTapas();

}

void ObjetoRevolucion::generaTapas(){


	if(carasTapas == 0){

		int tapaSuperior = getNumVertices()-2;
    int tapaInferior = getNumVertices()-1;

    //GENERA BASE
    cout << caras.size()/3 << " " << puntos.size()/3 << endl;

    for(int i=0;i<getNumVertices()-2-numVerticesInicio; i = i + numVerticesInicio ){
        //Si no va cambiar 2 por el 1
        cout <<"Creando cara : "<< i << " " << tapaInferior << " " << i+numVerticesInicio <<  endl;
        insertarCara(i,tapaInferior,i+numVerticesInicio);
        carasTapas++;
    }

    //GENERA TAPA -numVerticesInicio-2;
    for(int i=numVerticesInicio-1;i<getNumVertices()-numVerticesInicio-2; i = i +numVerticesInicio ){
        //Si no va cambiar 1 por el 2
        cout <<"Creando cara : "<< tapaSuperior << " " << i << " " << i+numVerticesInicio <<  endl;
       insertarCara(tapaSuperior,i,i+numVerticesInicio);
       carasTapas++;
    }

    insertarCara(0,getNumVertices()-numVerticesInicio-2,tapaInferior);
    carasTapas++;
    //Arreglar
    insertarCara(numVerticesInicio-1,getNumVertices()-2,getNumVertices()-3);
    carasTapas++;

	}

}

void ObjetoRevolucion::quitaTapas(){

  for(int i = 0 ; i < carasTapas*3 ; i++)
    caras.pop_back();

  carasTapas = 0;
}

void ObjetoRevolucion::leerPly(){
  std::string str;
  std::cout << "Introduzca la direccion del PLY de Revolucion: " << std::endl;
  cin >> str;

  if (access( str.c_str(), F_OK ) != -1) {
      puntos.clear();
      caras.clear();
      _file_ply *ply;
      ply = new _file_ply();
      std::vector<char> cstr(str.c_str(), str.c_str() + str.size() + 1);
      ply->open(&cstr[0]);
      std::vector<float> vertices;
      std::vector<int> caras;
      ply->read(vertices,caras);

      //setPuntos(vertices);
      bound.calcularBoundingBox(vertices);
      //setCaras(caras);
      puntosIniciales = vertices;
      generarRevolucion();

  } else {
      std::cerr << "Error , el archivo no existe" << std::endl;
      leerPly();
  }

}
