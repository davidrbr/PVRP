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
   vector < vector <int> > posibilidades;     //almacena todas las combinaciones de visitas posibles dentro del periodo de planificación (cada vector<int> es una combinación)
public:
   cliente ();
   cliente (int id, int x, int y, int dem, int nd, float tr);
   void setcid (int);
   void setxcord (int);
   void setycord (int);
   void setdemanda (int);
   void setndiasrecogida (int);
   void settrequerido (float);
   int getcid ();
   int getxcord ();
   int getycord ();
   int getdemanda ();
   int getndiasrecogida ();
   float gettrequerido ();
   int getnposibilidades ();
   vector <int> getposibilidad (int);
   bool comprobarcad (string);
   void perm (vector<vector<int> > &, vector<string>, string, int, int); //se le pasa el vector donde se almacenarán las posibilidades definitivas, periodo de planificación en string (hasta 9), un sting para la recursividad (""), ndíasderecogida, periodo de planificación) 
   void generarposibilidades (int);     //se le pasa el periodo de planificación
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
   void generartodaslasposibilidades (int);
   void seleccionarunaposibilidadporcliente ();
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
   vector < vector <cliente> > rutaoptima;
   vector <int> vehiculosrutaoptima;
   vector <int> vehiculosparcial;
   float costerutaoptima;
   vector <int> visitasintocable;
   vector <int> visitastotal;
   vector <int> visitasruta;
   int niteraciones;
public:
   ruteo ();
   ruteo (flota, clientela, int);
   void reset ();
   void setrutaoptima (vector < vector <cliente> >);
   void setcosterutaoptima (float);
   vector < vector <cliente> > getrutaoptima ();
   float getcosterutaoptima ();
   vector <cliente> getrutavehiculoconcreto (int);
   float generarcosterutaparcial (vector <cliente>);
   float generarcosterutatotal (vector < vector <cliente> >);
   int numeroaleatorio (int);
   void initvisitastotal ();
   void initvisitastotal2 ();
   void initvisitasruta ();
   void restarvisita (int);
   int visitasrestantes ();
   int visitasrestantesruta ();
   vector <cliente> ordenarposibilidades (int, vector <cliente>);
   vector <cliente> generarposibilidades ();
   vector <cliente> generarrutaparcial (int);
   vector < vector <cliente> > generarrutatotal ();
   void generarrutaoptima ();
   void mostrarrutaoptima ();
};

class ruteo2 {
private:
   flota laflota;
   clientela laclientela;
   vector < vector <cliente> > ruta;
   vector <int> vehiculos;
   float costeruta;
   vector < vector <int> > clientespordia;
   vector <int> visitasruta;
public:
   ruteo2 ();
   ruteo2 (flota, clientela);
   //setter y getter
   float getcosteruta ();
   vector < vector <cliente> > getruta ();
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

