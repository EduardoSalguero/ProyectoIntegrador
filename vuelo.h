#include <iostream>
#ifndef vuelo_h
#define vuelo_h

using namespace std;

#include "Fecha.h"
#include "avion.h"

class Vuelo{

private:
  string vuelo;
  string aerolinea;
  string destinoOrigen;
  string llegadaSalida;
  int pasajeros;
  Avion avion;
  Fecha fecha;


public:
  Vuelo();
  Vuelo(string,string,string,string,Avion,int,Fecha);
  void setVuelo(string);
  string getVuelo();
  void setAerolinea(string);
  string getAerolinea();
  void setDestinoOrigen(string);
  string getDestinoOrigen();
  void setLlegadaSalida(string);
  string getLlegadaSalida();
  void setAvion(Avion);
  Avion* getAvion();
  void setPasajeros(int);
  int getPasajeros();
  void setFecha(Fecha);
  Fecha* getFecha();
};
Vuelo::Vuelo() {
  Fecha c;
  Avion d;
  vuelo = " ";
  aerolinea = " ";
  destinoOrigen = " ";
  llegadaSalida = " ";
  avion = d;
  pasajeros = 0;
  fecha = c;
}
Vuelo::Vuelo(string vuelo,string aerolinea,string destinoOrigen,string llegadaSalida,Avion avion,int pasajeros,Fecha fecha) {
  this->vuelo = vuelo;
  this->aerolinea = aerolinea;
  this->destinoOrigen = destinoOrigen;
  this->llegadaSalida = llegadaSalida;
  this->avion = avion;
  this->pasajeros = pasajeros;
  this->fecha = fecha;
}

void Vuelo::setVuelo(string vuelo) {
  this->vuelo = vuelo;
}
void Vuelo::setAerolinea(string aerolinea) {
  this->aerolinea = aerolinea;
}
void Vuelo::setDestinoOrigen(string destinoOrigen) {
  this->destinoOrigen = destinoOrigen;
}
void Vuelo::setLlegadaSalida(string llegadaSalida) {
  this->llegadaSalida = llegadaSalida;
}
void Vuelo::setAvion(Avion avion) {
  this->avion = avion;
}
void Vuelo::setPasajeros(int pasajeros) {
  this->pasajeros = pasajeros;
}
void Vuelo::setFecha(Fecha fecha) {
  this->fecha = fecha;
}

string Vuelo::getVuelo() {
  return vuelo;
}
string Vuelo::getAerolinea() {
  return aerolinea;
}
string Vuelo::getDestinoOrigen() {
  return destinoOrigen;
}
string Vuelo::getLlegadaSalida() {
  return llegadaSalida;
}
Avion* Vuelo::getAvion() {
  return &avion;
}
int Vuelo::getPasajeros() {
  return pasajeros;
}
Fecha* Vuelo::getFecha() {
  return &fecha;
}
#endif
