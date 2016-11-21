#ifndef _LAMPARA_
#define _LAMPARA_

#include "objeto.h"
#include "cubo.h"
#include "amplificador.h"
#include "base.h"
#include "foco.h"
#include "cilindro.h"

class Lampara {

public:
  Lampara();
  void dibujar();
  void cambiarDibujado(int nuevo);
  void ampliar();
  void reducir();

  void incrementarBase();
  void decrementarBase();
  void incrementarUnion();
  void decrementarUnion();
  void incrementarFoco();
  void decrementarFoco();
  void interruptor();

  void aumentarVelocidad();
  void disminuirVelocidad();
  void paraAnimacion();


  void animacion();


private:
  
  double angulo_base;
  double angulo_union;
  double angulo_foco;
  bool pulsado;
  int ultimaPintada;
  int velocidadAnimacion;
  bool anima;
  int contadorAnimacion ;

  Cubo cubo;
  Base base;
  Amplificador ampli;
  Foco foco;
  Cilindro cilindro;

};

#endif
