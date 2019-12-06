#include <iostream>
#include <string>
#include <sstream>
#ifndef Fecha_h
#define Fecha_h

using namespace std;

class Fecha {

private:
    int ano;
    int mes;
    int dia;
    int hora;
    int minuto;

public:
    Fecha();
    Fecha(string,string);
    Fecha(int, int, int, int, int);
    void setDia(int);
    void setMes(int);
    void setAno(int);
    void setHora(int);
    void setMinuto(int);
    int getDia();
    int getMes();
    int getAno();
    int getHora();
    int getMinuto();
    string datos();
};

Fecha::Fecha() {
    dia = 0;
    mes = 0;
    ano = 0;
    hora = 0;
    minuto = 0;
}
Fecha::Fecha(string fecha_str, string hora_str) {
  ano = stoi(fecha_str.substr(0,4));
  mes = stoi(fecha_str.substr(5,7));
  dia = stoi(fecha_str.substr(8,10));
  hora = stoi(hora_str.substr(0,2));
  minuto = stoi(hora_str.substr(3,5));
}
Fecha::Fecha(int dia, int mes, int ano, int hora, int minuto) {
    this->dia = dia;
    this->mes = mes;
    this->ano = ano;
    this->hora = hora;
    this->minuto = minuto;
}
void Fecha::setDia(int dia) {
  this->dia = dia;
}
void Fecha::setMes(int mes) {
  this->mes = mes;
}
void Fecha::setAno(int ano) {
  this->ano = ano;
}
void Fecha::setHora(int hora) {
  this->hora = hora;
}
void Fecha::setMinuto(int minuto) {
  this->minuto = minuto;
}

int Fecha::getDia() {
    return dia;
}
int Fecha::getMes() {
    return mes;
}
int Fecha::getAno() {
    return ano;
}
int Fecha::getHora() {
    return hora;
}
int Fecha::getMinuto() {
    return minuto;
}
string Fecha::datos() {
    string laLas;
    if(hora == 1) {
        laLas = "la ";
    }
    else {
        laLas = "las ";
    }

    stringstream ss1,ss2,ss3,ss4,ss5;
    string ano1,mes1,dia1,hora1,minuto1;
    ss1<<ano;
    ss2<<mes;
    ss3<<dia;
    ss4<<hora;
    ss5<<minuto;

    ss1>>ano1;
    ss2>>mes1;
    ss3>>dia1;
    ss4>>hora1;
    ss5>>minuto1;

    return ano1 + "/" + mes1 + "/" + dia1 + " a " + laLas + hora1 + ":" + minuto1 + ".";
}

#endif
