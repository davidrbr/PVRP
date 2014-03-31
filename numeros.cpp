#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;


bool comprobarcad(string cad) {
//cout << "string: " << cad << endl;
   if (cad.length() > 1)
      for (int i = 1; i < cad.length(); i++) {
	int a, b;
        char aa, bb;
	
	aa = cad[i];
	bb = cad[i-1];
	//cout << "aa: " << aa << ", bb: " << bb << endl;
	a = aa - '0';
	b = bb - '0';
	//istringstream (cad[i]) >> a;
	//istringstream (cad[i-1]) >> b;
         if (a < b) {
	     //cout << "a: " << a << ", b: " << b << endl;
	     //cin.get();
            return false;
	 }
      }
      
   return true;
}

void perm(vector<vector<int> > &listado, vector<string> v, string act, int n, int r) {

   if (n == 0) {
      if (comprobarcad(act)) {
	 vector <int> aux;
         for (int i = 0; i < act.length(); i++) {
	    int num = act[i]- '0';
	    aux.push_back(num);
	 }
	 listado.push_back(aux);
	 //cout << "act: " << act << endl;
	
      }
         
   }
   else {
      for (int i = 0; i < r; i++) {
	 size_t found = act.find(v[i]);
         if (found == string :: npos)
	   perm(listado, v, act + v[i], n - 1, r);
     
      }
   }
}

void imprimir_listado(vector<vector<int> > v) {
   for (int i = 0; i < v.size(); i++) {
     for (int j = 0; j < v[i].size(); j++) {
        cout << v[i][j] << ", ";
     }
     cout << endl;
   }

}



int main () {
   //String[] elementos = "a,b,c,d,e".split(",");
   vector<vector<int> > v;
   vector<string> elementos;
   elementos.push_back("1");
   elementos.push_back("2");
   elementos.push_back("3");
   elementos.push_back("4");
   elementos.push_back("5");
   elementos.push_back("6");
   elementos.push_back("7");
   //elementos.push_back("8");
   //elementos.push_back("9");
   //elementos.push_back("10");
   
   int n = 1;                  //Tipos para escoger
   int r = elementos.size();   //total de elementos
   perm(v, elementos, "", n, r);
   imprimir_listado(v);
/*
  string a, b;
  a = "habbababba";
  b = "babba";
  size_t f = a.find("huble");
  if (f != string :: npos)
     cout << "encontrado" << endl;
  else
    cout << "no encontrado" << endl;
*/
}

/* package permutacion2;

public class Permutacion2 {

    public static void main(String[] args) {
        String[] elementos = "a,b,c,d,e".split(",");
        int n = 4;                  //Tipos para escoger
        int r = elementos.length;   //Elementos elegidos
        Perm2(elementos, "", n, r);
    }

    private static void Perm2(String[] elem, String act, int n, int r) {
        if (n == 0) {
            System.out.println(act);
        } else {
            for (int i = 0; i < r; i++) {
                if (!act.contains(elem[i])) { // Controla que no haya repeticiones
                    Perm2(elem, act + elem[i] + ", ", n - 1, r);
                }
            }
        }
    }
}

*/