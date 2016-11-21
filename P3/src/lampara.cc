#include "lampara.h"
#include<iostream>
#include <GL/glut.h>

Lampara::Lampara(){
  angulo_base=0.0;
  angulo_union=0.0;
  angulo_foco=0.0;
  pulsado = false;
  ultimaPintada = 0;
  velocidadAnimacion = 4;
  anima = false;
  contadorAnimacion = 0;
}

void Lampara::cambiarDibujado(int nuevo){ //0 puntos 1 lineas 2 solido 3 ajedrez
  base.cambiarDibujado(nuevo);
  cubo.cambiarDibujado(nuevo);
  foco.cambiarDibujado(nuevo);
  ampli.cambiarDibujado(nuevo);
  cilindro.cambiarDibujado(nuevo);

}
  void Lampara::incrementarBase(){
    //Rango -70 a 70
    if(angulo_base < 70)
      angulo_base = angulo_base + 2.0;
  }
  void Lampara::decrementarBase(){
    if(angulo_base > -70)
      angulo_base = angulo_base - 2.0;
  }
  void Lampara::incrementarUnion(){
    if(angulo_union < 60)
      angulo_union = angulo_union + 2.0;
  }
  void Lampara::decrementarUnion(){
    if(angulo_union > -60)
      angulo_union = angulo_union - 2.0;
  }
  void Lampara::incrementarFoco(){
    if(angulo_foco < 90)
      angulo_foco = angulo_foco + 2.0;
  }
  void Lampara::decrementarFoco(){
    if(angulo_foco > -90)
      angulo_foco = angulo_foco - 2.0;
  }

  void Lampara::interruptor(){
    pulsado = !pulsado;
    paraAnimacion();
  }

  void Lampara::aumentarVelocidad(){
    velocidadAnimacion--;
    //Control para evitar dividir entre 0
    if(velocidadAnimacion == 0){
      velocidadAnimacion = 1;
    }

  }
  void Lampara::disminuirVelocidad(){
    velocidadAnimacion++;
  }
  void Lampara::paraAnimacion(){
    anima = !anima;
  }


void Lampara::animacion(){

  int ahora = glutGet(GLUT_ELAPSED_TIME);

  if(ahora % velocidadAnimacion == 0 && ahora != ultimaPintada && anima){
    ultimaPintada = ahora;

    if(contadorAnimacion < 30){
      decrementarFoco();
      incrementarBase();
      decrementarUnion();
      contadorAnimacion++;
    }else{

      incrementarFoco();
      decrementarBase();
      incrementarUnion();
      contadorAnimacion++;
      if(contadorAnimacion == 60){
        contadorAnimacion = 0;
      }

    }
  }


}


void Lampara::dibujar(){

glPushMatrix();
  glScalef(10.0f,10.0f,10.0f); //Escalo esto para que se vea bien

  glPushMatrix();
    glTranslatef(0.0f,-1.0f,0.0f);
    glScalef(10.0f,2.0f,8.0f);
    base.dibujar();
  glPopMatrix();

  glPushMatrix();
    if(pulsado){
      glTranslatef(-2.0,-0.5f,0.0f);
    }else{
      glTranslatef(-2.0,0.0f,0.0f);
    }

    cilindro.dibujar();
  glPopMatrix();

//Aplicar rotacion base
glPushMatrix();
  glRotatef(angulo_base, 0.0, 0.0, 1.0);

  //Cilindro base para poder girar
  glPushMatrix();
    glRotatef(90.0, 1.0, 0.0, 0.0);
    cilindro.dibujar();
  glPopMatrix();

  glPushMatrix();
    glTranslatef(0.0f,7.5f,0.0f);
    glScalef(1.0f,15.0f,1.0f);
    cubo.dibujar();
  glPopMatrix();


    glPushMatrix();
      glTranslatef(0.0f,15.0f,0.0f);
      //Aplicar otra rotacion palo alto
      glRotatef(angulo_union, 0.0, 0.0, 1.0);
      glPushMatrix();
         glRotatef(90.0, 1.0, 0.0, 0.0);
         cilindro.dibujar();
      glPopMatrix();


      glPushMatrix();
        glTranslatef(7.5f,0.0f,0.0f);
        glScalef(15.0f,1.0f,1.0f);
        cubo.dibujar();
      glPopMatrix();

      glPushMatrix();
        glTranslatef(15.0f,0.0f,0.0f);
        glPushMatrix();
          //Aplicamos rotacion foco
          glRotatef(angulo_foco, 1.0, 0.0, 0.0);
          //Foco
          glPushMatrix();
            glScalef(4.0f,4.0f,4.0f);
            foco.dibujar();
          glPopMatrix();
          //Amplificador
          glPushMatrix();
            glTranslatef(0.0f,-2.5f,0.0f);
            glScalef(8.0f,1.0f,8.0f);
            ampli.dibujar();
          glPopMatrix();

        glPopMatrix();
      glPopMatrix();
    glPopMatrix();
    glPopMatrix();
  glPopMatrix();

}

void Lampara::ampliar(){

  base.ampliar();
  cubo.ampliar();
  foco.ampliar();
  ampli.ampliar();
}

void Lampara::reducir(){
  base.reducir();
  cubo.reducir();
  foco.reducir();
  ampli.reducir();
}
