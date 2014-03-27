#include "recogida.h"

/* Clase leerfichero */

leerfichero :: leerfichero () {
   
};

leerfichero :: leerfichero (string name, flota & tveh, clientela & tcli) { //le tengo que pasar una variable flota y clientela desde el main
   string aux;
   int numvehiculos = 0;
   int capacidad = 0;
   float horastr = 0.0;
   int id = 0;
   int x = 0;
   int y = 0;
   int dem = 0;
   int nd = 0;
   float tr = 0.0;
   
   nombrefichero = name;
   ifstream fe(nombrefichero.c_str());
   fe >> aux;                   //lee el nombre del fichero, situado en la primera línea del fichero
   fe >> aux;                   //lee la palabra VEHICLE
   fe >> aux;                   //lee la siguiente línea, también son palabras
   fe >> aux;
   fe >> aux;
   fe >> numvehiculos;          //lee el número de vehículos
   fe >> capacidad;             //lee la capacidad de caca vehículo
   fe >> horastr;               //lee las horas de trabajo de cada vehículo
   
   tveh.crearflota(numvehiculos, capacidad, horastr);
   
   fe >> aux;                   //lee la palabra CUSTOMER
   fe >> aux;                   //lee la siguiente línea, también son palabras
   fe >> aux;
   fe >> aux;
   fe >> aux;
   fe >> aux;
   fe >> aux;
   fe >> aux;
   
   int i = 0;
   
   while (!fe.eof()) {               //por cada una de las filas del fichero hasta que se termine dicho fichero, while not end of file
      fe >> id;                      //cojo seis elementos, los seis atributos del cliente
      fe >> x;
      fe >> y;
      fe >> dem;
      fe >> nd;
      fe >> tr;
      cliente caux (id, x, y, dem, nd, tr);         //creo un cliente auxiliar
      tcli.addcliente(caux);                        //introduzco el cliente en el vector de tcli a través de la función add cliente
   };
   
   fe.close();
};

void leerfichero :: setnombrefichero (string name) {
   nombrefichero = name;
};

string leerfichero :: getnombrefichero () {
   return nombrefichero;
};


/* Clase cliente */

cliente :: cliente () {
   
};

cliente :: cliente (int id, int x, int y, int dem, int nd, float tr) {
   cid = id;
   xcord = x;
   ycord = y;
   demanda = dem;
   ndiasrecogida = nd;
   trequerido = tr;
};

void cliente :: setcid (int a) {
   cid = a;
};

void cliente :: setxcord (int a) {
   xcord = a;
};

void cliente :: setycord (int a) {
   ycord = a;
};

void cliente :: setdemanda (int a) {
   demanda = a;
};

void cliente :: setndiasrecogida (int a) {
   ndiasrecogida = a;
};

void cliente :: settrequerido (float a) {
   trequerido = a;
};

int cliente :: getcid () {
   return cid;
};

int cliente :: getxcord () {
   return xcord;
};

int cliente :: getycord () {
   return ycord;
};

int cliente :: getdemanda () {
   return demanda;
};

int cliente :: getndiasrecogida () {
   return ndiasrecogida;
};

float cliente :: gettrequerido () {
   return trequerido;
};


/* Clase clientela */

clientela :: clientela () {
   
};

void clientela :: settotalclientes (vector <cliente> cli) {
   totalclientes = cli;
};

vector <cliente> clientela :: gettotalclientes () {
   return totalclientes;
};

int clientela :: getnclientes () {
   totalclientes.size();
};

cliente clientela :: getcliente (int n) {
   return totalclientes[n];
};

void clientela :: addcliente (cliente cli) {
   totalclientes.push_back(cli);
};

void clientela :: mostrarclientela () {
   cout << "Listado de clientes de la empresa" << endl;
   for (int i = 0; i < totalclientes.size(); i++) {
      
      cout << "i = " << i << endl;
      cout << "totalclientes.size() = " << totalclientes.size() << endl;
      
      cout << "ID: " << totalclientes[i].getcid() << endl;
      cout << "Coordenada X: " << totalclientes[i].getxcord() << endl;
      cout << "Coordenada Y: " << totalclientes[i].getycord() << endl;
      cout << "Demanda: " << totalclientes[i].getdemanda() << endl;
      cout << "Número de días de recogida: " << totalclientes[i].getndiasrecogida() << endl;
      cout << "Tiempo requerido en cada recogida: " << totalclientes[i].gettrequerido() << endl;
   };
   
};

void clientela :: generarmatrizdistancias () {
   for (int i = 0; i < totalclientes.size(); i++) {
      int x1 = totalclientes[i].getxcord();
      int y1 = totalclientes[i].getycord();
      vector <float> vaux;
      for (int j = 0; j < totalclientes.size(); j++) {
         int x2 = totalclientes[j].getxcord();
         int y2 = totalclientes[j].getycord();
         float aux = sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1));
         vaux.push_back(aux);
      };
      matrizdistancias.push_back(vaux);
      vaux.empty();
   };
};
   
void clientela :: mostrarmatrizdistancias () {
   for (int i = 0; i < totalclientes.size(); i++) {
      for (int j = 0; j < totalclientes.size(); j++)
         cout << "  " << matrizdistancias[i][j];
      cout << endl;
   };
};

vector <float> clientela :: devolverfilamatrizd (int i) {
   return matrizdistancias[i];
};

float clientela :: devolverdistanciadospuntos (int a, int b) {
   return matrizdistancias[a][b];
};


/* Clase vehiculo */

vehiculo :: vehiculo () {
   
};

vehiculo :: vehiculo (int id, int cap, float htr) {
   vid = id;
   capacidad = cap;
   horastrabajo = htr;
};

void vehiculo :: setvid (int a) {
   vid = a;
};

void vehiculo :: setcapacidad (int a) {
   capacidad = a;
};

void vehiculo :: sethorastrabajo (float a) {
   horastrabajo = a;
};

int vehiculo :: getvid () {
   return vid;
};

int vehiculo :: getcapacidad () {
   return capacidad;
};

float vehiculo :: gethorastrabajo () {
   return horastrabajo;
};


/* Clase flota */

flota :: flota () {
   
};

void flota :: crearflota (int id, int cap, float htr) {
   vehiculo vaux;
   for (int i = 0; i < id; i++) {
      vaux.setvid(i);
      vaux.setcapacidad(cap);
      vaux.sethorastrabajo(htr);
      totalvehiculos.push_back(vaux);
   };
};

void flota :: settotalvehiculos (vector <vehiculo> tv) {
   totalvehiculos = tv;
};

vector <vehiculo> flota :: gettotalvehiculos () {
   return totalvehiculos;
};

int flota :: getnvehiculos () {
   return totalvehiculos.size();
};

vehiculo flota :: getvehiculo (int n) {
   return totalvehiculos[n];
};

void flota :: mostrarflota () {
   cout << "Listado de vehículos de la flota" << endl;
   for (int i = 0; i < totalvehiculos.size(); i++) {
      cout << "ID: " << totalvehiculos[i].getvid() << endl;
      cout << "Capacidad: " << totalvehiculos[i].getcapacidad() << endl;
      cout << "Horas de trabajo: " << totalvehiculos[i].gethorastrabajo() << endl;
   };
};


/*  Clase ruteo  */

ruteo :: ruteo () {
   
};

ruteo :: ruteo (flota f, clientela c, int it) {
   srand((unsigned)time(NULL));
   laflota = f;
   laclientela = c;
   costerutaoptima = 9999;
   niteraciones = it;
};

void ruteo :: setrutaoptima (vector < vector <cliente> > ru) {
   rutaoptima = ru;
};

void ruteo :: setcosterutaoptima (float co) {
   costerutaoptima = co;
};

vector < vector <cliente> > ruteo :: getrutaoptima () {
   return rutaoptima;
};

float ruteo :: getcosterutaoptima () {
   return costerutaoptima;
};

vector <cliente> ruteo :: getrutavehiculoconcreto (int n) {
   return rutaoptima[n];
};

float ruteo :: generarcosterutaparcial (vector <cliente> ru) {
   float aux = 0.0;
   for (int i = 0; i < ru.size()-1; i++)
      aux += laclientela.devolverdistanciadospuntos(i, i+1);
   return aux;
};

float ruteo :: generarcosterutatotal (vector < vector <cliente> > ru) {
   float aux = 0.0;
   for (int i = 0; i < ru.size(); i++)
      aux += generarcosterutaparcial(ru[i]);
   return aux;
};

int ruteo :: numeroaleatorio (int size) {
   if (size == 1)
      return 0;
   else
      if (size == 2)
         return rand()%2;
      else
         return rand()%3;
};

void ruteo :: initvisitastotal () {
   int num = laclientela.getnclientes();
   cliente aux;
   for (int i = 0; i < num; i++) {
      aux = laclientela.getcliente(i);
      visitastotal.push_back(aux.getndiasrecogida());
      visitasruta.push_back(0);
   };
   visitastotal[0] = 0;
   visitasintocable = visitastotal;
};

void ruteo :: initvisitastotal2 () {
   visitastotal = visitasintocable;
};

void ruteo :: initvisitasruta () {
   int num = laclientela.getnclientes();
   for (int i = 0; i < num; i++)
      if (visitastotal[i] > 0)
         visitasruta[i] = 1;
      else
         visitasruta[i] = 0;
};

void ruteo :: restarvisita (int pos) {
   visitastotal[pos]--;
   visitasruta[pos]--;
};

int ruteo :: visitasrestantes () {
   int aux = 0;
   for (int i = 0; i < visitastotal.size(); i++)
      aux += visitastotal[i];
   return aux;
};

int ruteo :: visitasrestantesruta () {
   int aux = 0;
   for (int i = 0; i < visitasruta.size(); i++) {
      aux += visitasruta[i];
   };
   return aux;
};

vector <cliente> ruteo :: ordenarposibilidades (int a, vector <cliente> sinordenar) {
   vector <cliente> sin = sinordenar;
   vector <cliente> ordenados;
   float distancia;
   cliente minimo;
   int posicion;
   for (int i = 0; i < sinordenar.size()-1; i++) {  //por si hubiera que tenerlo en cuenta en algún momento, voy a ir eliminando dentro del primer bucle for elementos de sinordenar, así que va a ir siendo cada vez más pequeño
      float distanciaminima = 999;
      for (int j = 0; j < sin.size(); j++) {
         if (a != sin[j].getcid()) {
            distancia = laclientela.devolverdistanciadospuntos(a, sin[j].getcid());
            if (distancia < distanciaminima) {
               distanciaminima = distancia;
               minimo = sin[j];
               posicion = j;
            };
         };
      };
      ordenados.push_back(minimo);
      sin.erase(sin.begin()+posicion);
   };
   return ordenados;
};

vector <cliente> ruteo :: generarposibilidades ()  {
   int num = laclientela.getnclientes();
   vector <cliente> aux;
   for (int i = 1; i < num; i++) {
      if (visitasruta[i] == 1)
         aux.push_back(laclientela.getcliente(i));
   };
   return aux;
};

vector <cliente> ruteo :: generarrutaparcial (int n) {
   vehiculo vaux = laflota.getvehiculo(n);
   float capacidadvehiculo = vaux.getcapacidad();
   float horastrabajo = vaux.gethorastrabajo();
   float capacidadaux = 0.0;
   float horasaux = 0.0;
   vector <cliente> rutaux;
   int numcliente = 0;
   rutaux.push_back(laclientela.getcliente(numcliente));
   int naleatorio;
   bool salir = false;
   while ((capacidadaux < capacidadvehiculo) && (horasaux < horastrabajo) && (visitasrestantesruta() > 0) && (!salir)) {
      vector <cliente> cliaux = generarposibilidades();
      if (cliaux.size() > 1)
         cliaux = ordenarposibilidades(numcliente, cliaux);
      naleatorio = numeroaleatorio(cliaux.size());
      if (((horasaux + cliaux[naleatorio].gettrequerido()) <= horastrabajo) && ((capacidadaux + cliaux[naleatorio].getdemanda()) <= capacidadvehiculo)) {
         rutaux.push_back(cliaux[naleatorio]);
         restarvisita(cliaux[naleatorio].getcid());
         capacidadaux += cliaux[naleatorio].getdemanda();
         horasaux += cliaux[naleatorio].gettrequerido();
      }
      else
         salir = true;
   };
   rutaux.push_back(laclientela.getcliente(0));
   return rutaux;
};

vector < vector <cliente> > ruteo :: generarrutatotal () {
   vector < vector <cliente> > rutaux;
   vector <int> veaux;
   initvisitastotal2();
   int contadorvehiculo;
   int totalvehiculos = laflota.getnvehiculos();
   while (visitasrestantes() > 0) {
      contadorvehiculo = 0;
      initvisitasruta();
      while ((contadorvehiculo < totalvehiculos) && (visitasrestantesruta() > 0)) {
         rutaux.push_back(generarrutaparcial(contadorvehiculo));
         veaux.push_back(contadorvehiculo);
         contadorvehiculo++;
      };
   };
   vehiculosparcial = veaux;
   return rutaux;
};

void ruteo :: generarrutaoptima () {
   vector < vector <cliente> > aux;
   float costeaux;
   initvisitastotal();
   for (int i = 0; i < niteraciones; i++) {
      if (i == 0) {
         rutaoptima = generarrutatotal();
         vehiculosrutaoptima = vehiculosparcial;
         costerutaoptima = generarcosterutatotal(rutaoptima);
      }
      else {
         aux = generarrutatotal();
         costeaux = generarcosterutatotal(aux);
         if (costeaux < costerutaoptima) {
            rutaoptima = aux;
            vehiculosrutaoptima = vehiculosparcial;
            costerutaoptima = costeaux;
         };
      };
   };
};

void ruteo :: mostrarrutaoptima () {
   int cont = 0;
   for (int i = 0; i < rutaoptima.size(); i++) {
      if (vehiculosrutaoptima[i] == 0) {
         cont++;
         cout << "Día " << cont << endl;
      };
      cout << "Ruta numero " << i << ", vehiculo con id " << vehiculosrutaoptima[i] << ":";
      for (int j = 0; j < rutaoptima[i].size(); j++)
         cout << "  " << rutaoptima[i][j].getcid();
      cout << endl << "Coste de la ruta = " << generarcosterutaparcial(rutaoptima[i]) << endl;
      cout << endl;
   };
};


   
int main () {
   flota miflota;             //creo un elemento de la clase flota que se lo paso al constructor de leerfichero y le doy valor a su vector dentro
   clientela miclientela;     //creo un elemento de la clase clientela que se lo paso al constructor de leerfichero y le doy valor a su vector dentro
   
   cout << "Introduzca el nombre del fichero de entrada: ";
   string nombre;
   //cin >> nombre;
   nombre = "ficheroprueba.txt";
   
   cout << endl << "Extrayendo datos del fichero..." << endl;
   leerfichero lectura (nombre, miflota, miclientela);
   
   //miflota.mostrarflota();
   //miclientela.mostrarclientela();
   
   cout << "Generando matriz de distancias..." << endl;
   miclientela.generarmatrizdistancias();
   
   /*
   miclientela.mostrarmatrizdistancias();
   vector <float> cosa = miclientela.devolverfilamatrizd(5);
   for (int i = 0; i < cosa.size(); i++)
      cout << "cosa[" << i << "]: " << cosa[i] << endl;
   */
   
   cout << "Indique el número de iteraciones que desea realizar: ";
   int iteraciones;
   //cin >> iteraciones;
   iteraciones = 5;
   
   ruteo miruteo(miflota, miclientela, iteraciones);
   cout << endl << "Generando ruta óptima..." << endl;
   //miruteo.generarrutatotal();
   miruteo.generarrutaoptima();
   miruteo.mostrarrutaoptima();
   cout << "Coste de la ruta óptima = " << miruteo.getcosterutaoptima() << endl;
   return 0;
};