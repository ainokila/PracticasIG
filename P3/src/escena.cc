#ifdef _WIN32
#include <windows.h>
#endif
#include <cstdio>
#include <iostream>
#include <GL/gl.h>
#include <GL/glut.h>
#include "escena.h"
#include "lampara.h"




Escena::Escena(){
    Front_plane=50;
    Back_plane=2000;
    Observer_distance = 4*Front_plane;
    Observer_angle_x = Observer_angle_y=0;
    ejes.changeAxisSize(5000);

    objeto = NULL;
    objetorev = NULL;
    lampara = NULL;

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

  if(lampara != NULL)
    lampara->dibujar();
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

    //MODO DE DIBUJADO ->>

    case 'L':
      //Llamamos a modo lineas
      if(lampara != NULL)
        lampara->cambiarDibujado(1);

      if(objeto != NULL)
        objeto->cambiarDibujado(1);

      if(objetorev != NULL)
        objetorev->cambiarDibujado(1);
      break;

    case 'P':
      if(lampara != NULL)
        lampara->cambiarDibujado(0);

      if(objeto != NULL)
        objeto->cambiarDibujado(0);
      if(objetorev != NULL)
        objetorev->cambiarDibujado(0);
      break;

    case 'S':
      if(lampara != NULL)
        lampara->cambiarDibujado(2);

      if(objeto != NULL)
        objeto->cambiarDibujado(2);

      if(objetorev != NULL)
        objetorev->cambiarDibujado(2);
      break;

    case 'A':
      if(lampara != NULL)
        lampara->cambiarDibujado(3);
      if(objeto != NULL)
        objeto->cambiarDibujado(3);

      if(objetorev != NULL)
        objetorev->cambiarDibujado(3);
      break;

    //Tipo de Objeto ->

    case '1':
    if(objetorev != NULL){
      delete objetorev;
      objetorev = NULL;
    }
    if(lampara != NULL){
      delete lampara;
      lampara = NULL;
    }
    if(objeto == NULL)
      objeto = new Objeto();
    if(objeto != NULL)
      objeto->leerPly();
    break;

    case '2':
    if(objeto!=NULL){
      delete objeto;
      objeto = NULL;
    }
    if(lampara != NULL){
      delete lampara;
      lampara = NULL;
    }

    if(objetorev == NULL)
      objetorev = new ObjetoRevolucion(15.0f);
    if(objetorev != NULL)
      objetorev->leerPly();
    break;

    //Modelo Jerarquico
    case '3':
    if(objetorev!=NULL){
      delete objetorev;
      objetorev = NULL;
    }
    if(objeto!=NULL){
      delete objeto;
      objeto = NULL;
    }
    if(lampara == NULL)
      lampara = new Lampara();
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
      if(lampara != NULL)
          lampara->ampliar();

      break;
    case '-':
      if(objeto != NULL)
        objeto->reducir();
      if(objetorev != NULL)
        objetorev->reducir();
      if(lampara != NULL)
          lampara->reducir();
      break;

    case 'Z':
      if(lampara != NULL){
        lampara->incrementarFoco();
      }
      break;

    case 'X':
      if(lampara != NULL){
        lampara->decrementarFoco();
      }
      break;

    case 'C':
      if(lampara != NULL){
        lampara->incrementarUnion();
      }
      break;

    case 'V':
      if(lampara != NULL){
        lampara->decrementarUnion();
      }
      break;

    case 'B':
      if(lampara != NULL){
        lampara->incrementarBase();
      }
      break;

    case 'N':
      if(lampara != NULL){
        lampara->decrementarBase();
      }
      break;

    /*case '0':
      if(lampara != NULL){
        lampara->paraAnimacion();
      }
      break;*/

    case '9':
      if(lampara != NULL){
        lampara->disminuirVelocidad();
      }
      break;

    case '8':
      if(lampara != NULL){
        lampara->aumentarVelocidad();
      }
      break;

    case ',':
      if(lampara != NULL){
        lampara->interruptor();
      }
      break;
  }

  return 0;
}

void Escena::animacion(){
  if(lampara != NULL){
    lampara->animacion();
    //lampara->dibujar();
  }
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
