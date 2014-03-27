#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
#include <cstdlib>

using namespace std;

class cliente {
private:
   int cid;
   int xcord;
   int ycord;
   int demanda;
   int ndiasrecogida;
   float trequerido;
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
};

class clientela {
private:
   vector <cliente> totalclientes;
   vector < vector <float> >  matrizdistancias;
public:
   clientela ();
   void settotalclientes (vector <cliente>);
   vector <cliente> gettotalclientes ();
   int getnclientes ();
   cliente getcliente (int);
   void addcliente (cliente);
   void mostrarclientela ();
   void generarmatrizdistancias ();
   void mostrarmatrizdistancias ();
   vector <float> devolverfilamatrizd (int);
   float devolverdistanciadospuntos (int, int);
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
public:
   flota ();
   void crearflota (int id, int cap, float htr);
   void settotalvehiculos (vector <vehiculo>);
   vector <vehiculo> gettotalvehiculos ();
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
