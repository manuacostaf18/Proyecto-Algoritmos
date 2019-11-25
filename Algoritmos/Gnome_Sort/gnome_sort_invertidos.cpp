#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "vec.hpp"
#include <set>
#include <sys/time.h>
using namespace std;

//Funciones adicionales
double gettime(){
  struct timeval tp;
  gettimeofday(&tp, NULL);
  return tp.tv_sec + tp.tv_usec/(double)1.0e6;
}

void swap(int i, int j, Vec& vector){
  int temp = vector.get(i);
  vector.set(i, vector.get(j));
  vector.set(j, temp);
}

//Algoritmo
void gnome_sort(Vec& vector, int sz){
	int index = 0;

  while(index < sz){
    if(index == 0) index++;
    if (vector.get(index) >= vector.get(index-1)) index++;
    else{
      swap(index, index-1, vector);
      index--;
    }
  }
}

int main(){
    srand(time(NULL));

  //Creando los 5 vectores invertidos pero invertidos, de tamaños diferentes
  Vec vector1_invertido;
  Vec vector2_invertido;
  Vec vector3_invertido;
  Vec vector4_invertido;
  Vec vector5_invertido;

  for(int i = 5; i > 0; i--) vector1_invertido.push_back(i);
  for(int i = 10; i > 0; i--) vector2_invertido.push_back(i);
  for(int i = 50; i > 0; i--) vector3_invertido.push_back(i);
  for(int i = 100; i > 0; i--) vector4_invertido.push_back(i);
  for(int i = 1000; i > 0; i--) vector5_invertido.push_back(i);

  //Imprimiendo los vectores invertidos (opcional)
  /*cout << endl << "Vector 1 invertido: " << endl;
  vector1_invertido.display();
  cout << endl << "Vector 2 invertido: " << endl;
  vector2_invertido.display();
  cout << endl << "Vector 3 invertido: " << endl;
  vector3_invertido.display();
  cout <<  endl << "Vector 4 invertido: " << endl;
  vector4_invertido.display();
  cout << endl << "Vector 5 invertido: " << endl;
  vector5_invertido.display();*/


  //Probando el algoritmo con cada uno de los 5 vectores invertidos.
  int szvec1 = vector1_invertido.getsize();
  double t1_0 = gettime();
	gnome_sort(vector1_invertido, szvec1);
	double t1_1 = gettime();
	double t1 = t1_1 - t1_0;
	cout << "Tiempo tomado ordenando al vector1_invertido = " << t1 << endl;

  int szvec2 = vector2_invertido.getsize();
	double t2_0 = gettime();
	gnome_sort(vector2_invertido, szvec2);
	double t2_1 = gettime();
	double t2 = t2_1 - t2_0;
	cout << "Tiempo tomado ordenando al vector2_invertido = " << t2 << endl;

  int szvec3 = vector3_invertido.getsize();
  double t3_0 = gettime();
	gnome_sort(vector3_invertido, szvec3);
	double t3_1 = gettime();
	double t3 = t3_1 - t3_0;
	cout << "Tiempo tomado ordenando al vector3_invertido = " << t3 << endl;

  int szvec4 = vector4_invertido.getsize();
	double t4_0 = gettime();
	gnome_sort(vector4_invertido, szvec4);
	double t4_1 = gettime();
	double t4 = t4_1 - t4_0;
	cout << "Tiempo tomado ordenando al vector4_invertido = " << t4 << endl;

  int szvec5 = vector5_invertido.getsize();
	double t5_0 = gettime();
	gnome_sort(vector5_invertido, szvec5);
	double t5_1 = gettime();
	double t5 = t5_1 - t5_0;
	cout << "Tiempo tomado ordenando al vector5_invertido = " << t5 << endl;

	//Imprimiendo los vectores invertidos, ya ordenado, después del algoritmo (opcional)
	/*cout << endl << "Vector 1 invertido ya ordenado: " << endl;
	vector1_invertido.display();
	cout << endl << "Vector 2 invertido ya ordenado: " << endl;
	vector2_invertido.display();
	cout << endl << "Vector 3 invertido ya ordenado: " << endl;
	vector3_invertido.display();
	cout << endl << "Vector 4 invertido ya ordenado: " << endl;
	vector4_invertido.display();
	cout << endl << "Vector 5 invertido ya ordenado: " << endl;
	vector5_invertido.display();*/

    return 0;
}
