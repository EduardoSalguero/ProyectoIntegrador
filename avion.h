#include <iostream>
#ifndef avion_h
#define avion_h

using namespace std;

class Avion{

private:

  int capacidad;
  string modelo;

public:

  Avion();
  Avion(int,string);
  void setCapacidad(int);
  int getCapacidad();
  void setModelo(string);
  string getModelo();
};

Avion::Avion() {
  capacidad = 0;
  modelo = "X-X-X-X-X-X";

}
Avion::Avion(int capacidad, string modelo) {
  this-> capacidad = capacidad;
  this-> modelo = modelo;
}
void Avion::setCapacidad(int capacidad) {
  this-> capacidad = capacidad;
}
void Avion::setModelo (string modelo) {
  this-> modelo = modelo;
}
int Avion::getCapacidad() {
  return capacidad;
}
string Avion::getModelo() {
  return modelo;
}
#endif
