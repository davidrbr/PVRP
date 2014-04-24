#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <cstdlib>
#include <sstream>

using namespace std;

class cliente {
private:
   int cid;
   int xcord;
   int ycord;
   int demanda;
   int ndiasrecogida;
   float trequerido;
   vector <int> diasrecogida;
   vector < vector <int> > posibilidades;
public:
   cliente ();
   cliente (int id, int x, int y, int dem, int nd, float tr);
   cliente (int id, int x, int y, int dem, int nd, vector <int> dias);
   void setcid (int);
   void setxcord (int);
   void setycord (int);
   void setdemanda (int);
   void setndiasrecogida (int);
   void settrequerido (float);
   void setdiasrecogida (vector <int>);
   int getcid ();
   int getxcord ();
   int getycord ();
   int getdemanda ();
   int getndiasrecogida ();
   float gettrequerido ();
   vector <int> getdiasrecogida ();
   int getnposibilidades ();
   vector <int> getposibilidad (int);
   void mostrardiasrecogida ();
};

class clientela {
private:
   vector <cliente> totalclientes;
   vector < vector <float> >  matrizdistancias;
   vector < vector <int> > posibilidadcliente;
public:
   clientela ();
   void settotalclientes (vector <cliente>);
   vector <cliente> gettotalclientes ();
   int getnclientes ();
   cliente getcliente (int);
   vector < vector <int> > getposibilidadcliente ();
   void addcliente (cliente);
   void mostrarclientela ();
   void generarmatrizdistancias ();
   void mostrarmatrizdistancias ();
   vector <float> devolverfilamatrizd (int);
   float devolverdistanciadospuntos (int, int);
   void rellenarposibilidadcliente ();
   void mostrarposibilidadcliente ();
};

class vehiculo {
private:
   int vid;
   int capacidad;
   float horastrabajo;
public:
   vehiculo ();
   vehiculo (int id, int cap, float htr);
   void setvid (int);
   void setcapacidad (int);
   void sethorastrabajo (float);
   int getvid ();
   int getcapacidad ();
   float gethorastrabajo ();
};

class flota {
private:
   vector <vehiculo> totalvehiculos;
   int periodoplanificacion;
public:
   flota ();
   void crearflota (int id, int cap, float htr);
   void settotalvehiculos (vector <vehiculo>);
   void setperiodoplanificacion (int);
   vector <vehiculo> gettotalvehiculos ();
   int getperiodoplanificacion ();
   int getnvehiculos ();
   vehiculo getvehiculo (int);
   void mostrarflota ();
};

class leerfichero {
private:
   string nombrefichero;
public:
   leerfichero ();
   leerfichero (string, flota &, clientela &);
   void setnombrefichero (string);
   string getnombrefichero ();
};

class ruteo {
private:
   flota laflota;
   clientela laclientela;
   vector < vector <cliente> > ruta;
   vector <int> vehiculos;
   float costeruta;
   vector < vector <int> > clientespordia;
   vector <int> visitasruta;
public:
   ruteo ();
   ruteo (flota, clientela);
   float getcosteruta ();
   vector < vector <cliente> > getruta ();
   void mostrarclientespordia ();
   void generarclientespordia ();
   float generarcosterutaparcial (vector <cliente>);
   void generarcosteruta (vector < vector <cliente> >);
   void restarvisita (int);
   int visitasrutarestantes ();
   void actualizarvisitasruta (int);
   int numeroaleatorio (int);
   vector <cliente> ordenarposibilidades (int, vector <cliente>);
   vector <cliente> generarposibilidades ();
   vector <cliente> generarrutaparcial (int);
   void generarruta ();
   void mostrarruta ();
};

