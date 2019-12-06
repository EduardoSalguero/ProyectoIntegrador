#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

#include "vuelo.h"
#include "Fecha.h"
#include "avion.h"

void diasMayorSatu(Vuelo[],int);
void pasajerosAtDia(Vuelo[],int);
void salidasLlegadasProm(Vuelo[],int);
void salidasLlegadasAero(Vuelo[],int);
void porcentajeCapacidadAv(Vuelo[],int);

int main() {
  Vuelo vuelos[2600];
  ifstream file("Vuelos.txt",ios::in);
  ifstream file2("aviones.txt",ios::in);
  ifstream file3("llegadas_salidas.txt",ios::in);
  int renglo = 0,casti = 0, opc = 0,resp = 0;
  string aero[2600][6];

  while(file >> aero[renglo][0] >> aero[renglo][1] >> aero[renglo][2] >> aero[renglo][3] >> aero[renglo][4] >> aero[renglo][5]) {
    vuelos[renglo].setVuelo(aero[renglo][0]);
    vuelos[renglo].setAerolinea(aero[renglo][1]);
    vuelos[renglo].setDestinoOrigen(aero[renglo][2]);
    vuelos[renglo].setLlegadaSalida(aero[renglo][3]);
    Avion avion;
    avion.setModelo(aero[renglo][4]);
    vuelos[renglo].setAvion(avion);
    istringstream(aero[renglo][5]) >> casti;
    vuelos[renglo].setPasajeros(casti);
    renglo = renglo + 1;
  }
  file.close();
  int renglo2 = 0;
  casti = 0;

  while(file2 >> aero[renglo2][0] >> aero[renglo2][1]) {
    renglo2 = renglo2 + 1;
  }
  file2.close();

  for (int x = 0 ; x < renglo ; x++) {
    for (int z = 0; z < renglo2 ; z++) {
      if (aero[z][0] == vuelos[x].getAvion()->getModelo()) {
        istringstream(aero[z][1]) >> casti;
        vuelos[x].getAvion()->setCapacidad(casti);
      }
    }
  }
  int renglo3 = 0;
  Fecha temp[2600];

  while(file3 >> aero[renglo3][0] >> aero[renglo3][1] >> aero[renglo3][2] >> aero[renglo][3]) {
    Fecha c(aero[renglo3][0],aero[renglo3][1]);
    temp[renglo3] = c;
    renglo3 = renglo3 + 1 ;
  }
  file3.close();

  for (int x = 0 ; x < renglo ; x++) {
    for (int z = 0; z < renglo3 ; z++) {
      if (aero[z][2] == vuelos[x].getVuelo()) {
        //AÑO/MES/DIA
        vuelos[x].getFecha()->setAno(temp[z].getAno());
        vuelos[x].getFecha()->setMes(temp[z].getMes());
        vuelos[x].getFecha()->setDia(temp[z].getDia());
        //HORA/MIN
        vuelos[x].getFecha()->setHora(temp[z].getHora());
        vuelos[x].getFecha()->setMinuto(temp[z].getMinuto());
      }
    }
  }
  do {
    system("cls");
    cout << "Introduzca una opcion: " << endl;
    cout <<" "<<endl;
    cout << "1) Dias con mayor saturacion" << endl;
    cout << "2) Salidas/llegadas Promedio" << endl;
    cout << "3) Salidas/llegadas Aerolinea" << endl;
    cout << "4) Pasajeros atendidos por dia" << endl;
    cout << "5) Porcentaje promedio de capacidad utilizada" << endl;
    cout << "6) Exit"<<endl;
    cin >> opc;
    system("cls");

    switch(opc) {
      case 1: diasMayorSatu(vuelos,renglo);
        break;
      case 2: salidasLlegadasProm(vuelos,renglo);
        break;
      case 3: salidasLlegadasAero(vuelos,renglo);
        break;
      case 4: pasajerosAtDia(vuelos,renglo);
        break;
      case 5: porcentajeCapacidadAv(vuelos,renglo);
        break;
      case 6:
        break;
      default: cout << "Introduzca una opcion correcta" << endl;
    }
    cout << " " << endl;
    cout << "Desea volver al menu? (1 = si /2 = no): ";
    cin >> resp;

  }while(resp != 2);

  return 0;
}

void diasMayorSatu(Vuelo vuelos[],int renglo) {

  bool dias[32];
  int horas[24],mayor = 0,indiceMa = 0;

  for (int i = 0; i < 32; i++) {
    dias[i] = false;
  }
  //conseguir cuantos dias diferentes hay
  for (int x = 0; x < renglo; x++) {
    dias[vuelos[x].getFecha()->getDia()] = true;
  }
  for (int i = 0; i < 32 ; i++) {
    if (dias[i] == true) {
      for(int x = 0; x < 24; x++ ) {
        horas[x] = 0;
      }
      for(int x = 0 ; x < renglo ; x++) {
        if (vuelos[x].getFecha()->getDia() == i) {
          horas[vuelos[x].getFecha()->getHora()] = vuelos[x].getPasajeros() + horas[vuelos[x].getFecha()->getHora()];
        }
      }
      for(int x = 0;x < 24; x++ ) {
        if (horas[x] > mayor) {
          mayor = horas[x];
          indiceMa = x;
        }
      }
      cout << "1. La hora con mayor saturacion del dia " << i << " es las " << indiceMa << ":00 con " << horas[indiceMa] << " personas" << endl;
   }
 }
}
void pasajerosAtDia(Vuelo vuelos[], int renglo) {

  bool dias[32];
  int pasaTot = 0;

  for (int i = 0; i < 32; i++) {
    dias[i] = false;
  }
  //conseguir cuantos dias diferentes hay
  for (int x = 0; x < renglo ; x++) {
    dias[vuelos[x].getFecha()->getDia()] = true;
  }
  for (int i = 0; i < 32 ; i++) {
    //modificacion
    pasaTot = 0;
    if (dias[i] == true) {
      for(int x = 0 ; x < renglo ; x++) {
        if (vuelos[x].getFecha()->getDia() == i) {
          pasaTot = vuelos[x].getPasajeros() + pasaTot;
        }
      }
      cout << "5. El total de pasajeros atendidos por dia es " << pasaTot << endl;
   }
 }
}
void salidasLlegadasProm(Vuelo vuelos[],int renglo) {

  cout << "2. llegadas por hora promedio " << endl;
  cout << "3. Salidas por hora promedio " << endl;
  int llegada[24][2];

      for(int x = 0; x < 24; x++ ) {
        llegada[x][0] = 0;
        llegada[x][1] = 0;
      }
      for(int x = 0 ; x < renglo ; x++) {
        if(vuelos[x].getLlegadaSalida() == "A") {
          llegada[vuelos[x].getFecha()->getHora()][0]++;
        }
        else if (vuelos[x].getLlegadaSalida() == "S") {
          llegada[vuelos[x].getFecha()->getHora()][1]++;
        }
      }
      for(int x = 0; x < 24; x++ ) {
        cout << "hora " << x << ": " << llegada[x][1] << " Salidas " << llegada[x][0] << " Llegadas" << " promedio" << endl;
      }
}
void salidasLlegadasAero(Vuelo vuelos[], int renglo) {
  cout << "4. llegadas/Salidas por Aerolinea " << endl;

  int vuelosDiferentes = 1;
  string c;
  c = vuelos[0].getAerolinea();
  //Encuentra cuantos vuelos diferentes existen
  for (int x = 0; x < renglo ; x++) {
    if(vuelos[x].getAerolinea() != c ) {
      c = vuelos[x].getAerolinea();
      vuelosDiferentes++;
    }
  }
  string aero[vuelosDiferentes];
  c = vuelos[0].getAerolinea();
  int lineas = 0;

  for (int x = 0; x < renglo ; x++) {
      if (x == 0) {
        aero[lineas] = c;
        lineas++;
      }
      else if (vuelos[x].getAerolinea() != c ) {
        c = vuelos[x].getAerolinea();
        aero[lineas] = c;
        lineas++;
      }
  }
  int llegada[vuelosDiferentes][2];

      for(int x = 0; x < vuelosDiferentes; x++ ) {
        llegada[x][0] = 0;
        llegada[x][1] = 0;
      }
      for (int z = 0 ; z < vuelosDiferentes; z++){
        for(int x = 0 ; x < renglo ; x++) {
          if(vuelos[x].getLlegadaSalida() == "A" && vuelos[x].getAerolinea() == aero[z]) {
            llegada[z][0]++;
          }
          else if (vuelos[x].getLlegadaSalida() == "S" && vuelos[x].getAerolinea() == aero[z]) {
            llegada[z][1]++;
          }
        }
     }
      for(int x = 0; x < vuelosDiferentes; x++ ) {
        cout << "Aerolinea " << aero[x] << ": " << llegada[x][1] << " Salidas " << llegada[x][0] << " Llegadas" << endl;
      }
}
void porcentajeCapacidadAv(Vuelo vuelos[], int renglo) {

  cout << "6. Porcentaje promedio de capacidad utilizada en los aviones " << endl;
    //cantidad de pasajeros entre la capacidad de pasajeros
  int cantidadPasajerosTot = 0, capacidadPasajerosTot = 0;
  double porc;

  for (int x = 0; x < renglo ; x++ ) {
    cantidadPasajerosTot = cantidadPasajerosTot + vuelos[x].getPasajeros();
    capacidadPasajerosTot = capacidadPasajerosTot + vuelos[x].getAvion()->getCapacidad();
  }
  porc = (double)cantidadPasajerosTot /(double)capacidadPasajerosTot;
  cout << "Porcentaje promedio de capacidad: " << cantidadPasajerosTot << " / " << capacidadPasajerosTot << " = " << porc*100 << " %" << endl;
}
