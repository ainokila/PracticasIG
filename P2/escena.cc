#ifdef _WIN32
#include <windows.h>
#endif
#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include "escena.h"



Escena::Escena(){
    Front_plane=50;
    Back_plane=2000;
    Observer_distance = 4*Front_plane;
    Observer_angle_x = Observer_angle_y=0;
    ejes.changeAxisSize(5000);

    objeto = NULL;
    objetorev = NULL;

    //Se crea un cubo
    //cubo = new Cubo();
    //objeto = new Tetraedro();
    /*

    std::vector<float> aux;
    aux.push_back(1.0f);
    aux.push_back(1.0f);
    aux.push_back(0.0f);

    aux.push_back(1.0f);
    aux.push_back(0.5f);
    aux.push_back(0.0f);

    aux.push_back(1.5f);
    aux.push_back(0.0f);
    aux.push_back(0.0f);

    aux.push_back(1.0f);
    aux.push_back(-0.5f);
    aux.push_back(0.0f);

    aux.push_back(1.0f);
    aux.push_back(-1.0f);
    aux.push_back(0.0f);




    objeto = new ObjetoRevolucion(aux,15);*/
}

void Escena::inicializar(int UI_window_width,int UI_window_height) {

	glClearColor(1,1,1,1);// se indica cual sera el color para limpiar la ventana	(r,v,a,al)

	glEnable(GL_DEPTH_TEST);	// se habilita el z-bufer

	this->change_projection();
	Width=UI_window_width/10;
	Height=UI_window_height/10;
	glViewport(0,0,UI_window_width,UI_window_height);

}


//**************************************************************************
// Funcion que dibuja objetos en la escena
//***************************************************************************
void Escena::draw_objects() {

  //cubo->dibujar();

  if(objeto != NULL)
    objeto->dibujar();

  if(objetorev != NULL)
    objetorev->dibujar();

}



void Escena::dibujar() {

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT ); // Limpiar la pantalla
	change_observer();
	draw_axis();
	draw_objects();
}

int Escena::teclaPulsada(unsigned char Tecla1,int x,int y) {

    std::cout << "Tecla " << Tecla1<< std::endl;

  switch (toupper(Tecla1)) {
    case 'Q':
      return 1;
      break;
    case 'L':
      //Llamamos a modo lineas
      if(objeto != NULL)
        objeto->cambiarDibujado(1);

      if(objetorev != NULL)
        objetorev->cambiarDibujado(1);
      break;
    case 'P':
      if(objeto != NULL)
        objeto->cambiarDibujado(0);
      if(objetorev != NULL)
        objetorev->cambiarDibujado(0);
      break;
    case 'S':
      if(objeto != NULL)
        objeto->cambiarDibujado(2);

      if(objetorev != NULL)
        objetorev->cambiarDibujado(2);
      break;

    case 'C':
    if(objetorev != NULL){
      delete objetorev;
      objetorev = NULL;
    }
    if(objeto == NULL)
      objeto = new Objeto();
    if(objeto != NULL)
      objeto->leerPly();
    break;

    case 'Z':
    if(objeto!=NULL){
      delete objeto;
      objeto = NULL;
    }
    if(objetorev == NULL){
      std::vector<float> aux;
      aux.push_back(0.0f);  aux.push_back(0.1f);  aux.push_back(0.0f);
      aux.push_back(0.7f);  aux.push_back(0.1f);  aux.push_back(0.0f);
      aux.push_back(1.0f);  aux.push_back(0.0f);  aux.push_back(0.0f);
      aux.push_back(1.1f);  aux.push_back(0.0f);  aux.push_back(0.0f);
      aux.push_back(1.0f);  aux.push_back(0.5f);  aux.push_back(0.0f);
      aux.push_back(0.5f);  aux.push_back(1.0f);  aux.push_back(0.0f);
      aux.push_back(1.0f);  aux.push_back(2.0f);  aux.push_back(0.0f);
      aux.push_back(1.5f);  aux.push_back(3.0f);  aux.push_back(0.0f);
      aux.push_back(1.5f);  aux.push_back(4.0f);  aux.push_back(0.0f);
      aux.push_back(1.5f);  aux.push_back(5.0f);  aux.push_back(0.0f);
      aux.push_back(1.5f);  aux.push_back(6.0f);  aux.push_back(0.0f);
      aux.push_back(1.25f);  aux.push_back(6.0f);  aux.push_back(0.0f);
      aux.push_back(1.25f);  aux.push_back(5.0f);  aux.push_back(0.0f);
      aux.push_back(1.0f);  aux.push_back(4.0f);  aux.push_back(0.0f);
      aux.push_back(0.0f);  aux.push_back(3.0f);  aux.push_back(0.0f);

      objetorev = new ObjetoRevolucion(aux,30.0f);
    }
    //if(objetorev != NULL){
      //objetorev->leerPly();
    //}

    break;

    case 'R':
    if(objeto!=NULL){
      delete objeto;
      objeto = NULL;
    }
    if(objetorev == NULL)
      objetorev = new ObjetoRevolucion(30.0f);
    if(objetorev != NULL)
      objetorev->leerPly();
    break;

    case 'T':
    if(objetorev != NULL)
      objetorev->generaTapas();
    break;

    case 'E':
    if(objetorev != NULL)
      objetorev->quitaTapas();
    break;

    case '+':
      if(objeto != NULL)
        objeto->ampliar();
      if(objetorev != NULL)
        objetorev->ampliar();
      break;
    case '-':
      if(objeto != NULL)
        objeto->reducir();
      if(objetorev != NULL)
        objetorev->reducir();
      break;
  }

  return 0;
}

void Escena::teclaEspecial(int Tecla1,int x,int y) {
switch (Tecla1){
	case GLUT_KEY_LEFT:Observer_angle_y--;break;
	case GLUT_KEY_RIGHT:Observer_angle_y++;break;
	case GLUT_KEY_UP:Observer_angle_x--;break;
	case GLUT_KEY_DOWN:Observer_angle_x++;break;
	case GLUT_KEY_PAGE_UP:Observer_distance*=1.2;break;
	case GLUT_KEY_PAGE_DOWN:Observer_distance/=1.2;break;
	}

	//std::cout << Observer_distance << std::endl;
}


//**************************************************************************
// Funcion para definir la transformaci�n de proyeccion
//***************************************************************************

void Escena::change_projection()  {
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glFrustum(-Width,Width,-Height,Height,Front_plane,Back_plane);
}


void Escena::redimensionar(int newWidth,int newHeight) {
change_projection();
Width=newWidth/10;
Height=newHeight/10;
glViewport(0,0,newWidth,newHeight);
}


//**************************************************************************
// Funcion para definir la transformaci�n de vista (posicionar la camara)
//***************************************************************************



void Escena::change_observer() {

// posicion del observador
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
glTranslatef(0,0,-Observer_distance);
glRotatef(Observer_angle_x,1,0,0);
glRotatef(Observer_angle_y,0,1,0);
}


//**************************************************************************
// Funcion que dibuja los ejes utilizando la primitiva grafica de lineas
//***************************************************************************

void Escena::draw_axis()
{
ejes.draw();
}
