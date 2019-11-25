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
void heapify(Vec& vector, int n, int i){
  int largest = i;
  int l = 2*i + 1;
  int r = 2*i + 2;

  if (l < n && vector.get(l) > vector.get(largest)) largest = l;

  if (r < n && vector.get(r) > vector.get(largest)) largest = r;

  if (largest != i){
    swap (i, largest, vector);
    heapify(vector, n, largest);
  }
}

void heap_sort(Vec& vector, int n){
  for (int i = n/2-1; i>=0; i--){
    heapify(vector, n, i);
  }

  for (int i = n-1; i>=0; i--){
    swap(0, i, vector);
    heapify(vector, i, 0);
  }
}

int main(){
    srand(time(NULL));

	//Creando los 5 vectores desordenados, de tamaños diferentes
	Vec vector1_desordenado;
	Vec vector2_desordenado;
	Vec vector3_desordenado;
	Vec vector4_desordenado;
	Vec vector5_desordenado;

	for(int i = 1; i < 6; i++){
        int num = 1 + rand() % (101 - 1);
        vector1_desordenado.push_back(num);
    }
    for(int i = 1; i < 11; i++){
        int num = 1 + rand() % (101 - 1);
        vector2_desordenado.push_back(num);
    }
    for(int i = 1; i < 51; i++){
        int num = 1 + rand() % (501 - 1);
        vector3_desordenado.push_back(num);
    }
    for(int i = 1; i < 101; i++){
        int num = 1 + rand() % (501 - 1);
        vector4_desordenado.push_back(num);
    }
    for(int i = 1; i < 1001; i++){
        int num = 1 + rand() % (1001 - 1);
        vector5_desordenado.push_back(num);
    }

  //Imprimiendo los vectores desordenados (opcional)
  /*cout << endl << "Vector 1 desordenado: " << endl;
  vector1_desordenado.display();
  cout << endl << "Vector 2 desordenado: " << endl;
  vector2_desordenado.display();
  cout << endl << "Vector 3 desordenado: " << endl;
  vector3_desordenado.display();
  cout << endl << "Vector 4 desordenado: " << endl;
  vector4_desordenado.display();
  cout << endl << "Vector 5 desordenado: " << endl;
  vector5_desordenado.display();*/

  //Probando el algoritmo con cada uno de los 5 vectores desordenados.
  int n1 = vector1_desordenado.getsize();
  double t1_0 = gettime();
	heap_sort(vector1_desordenado, n1);
	double t1_1 = gettime();
	double t1 = t1_1 - t1_0;
	cout << "Tiempo tomado ordenando al vector1_desordenado = " << t1 << endl;

  int n2 = vector2_desordenado.getsize();
  double t2_0 = gettime();
	heap_sort(vector2_desordenado, n2);
	double t2_1 = gettime();
	double t2 = t2_1 - t2_0;
	cout << "Tiempo tomado ordenando al vector2_desordenado = " << t2 << endl;

  int n3 = vector3_desordenado.getsize();
  double t3_0 = gettime();
	heap_sort(vector3_desordenado, n3);
	double t3_1 = gettime();
	double t3 = t3_1 - t3_0;
	cout << "Tiempo tomado ordenando al vector3_desordenado = " << t3 << endl;

  int n4 = vector4_desordenado.getsize();
  double t4_0 = gettime();
	heap_sort(vector4_desordenado, n4);
	double t4_1 = gettime();
	double t4 = t4_1 - t4_0;
	cout << "Tiempo tomado ordenando al vector4_desordenado = " << t4 << endl;

  int n5 = vector5_desordenado.getsize();
	double t5_0 = gettime();
	heap_sort(vector5_desordenado, n5);
	double t5_1 = gettime();
	double t5 = t5_1 - t5_0;
	cout << "Tiempo tomado ordenando al vector5_desordenado = " << t5 << endl;

	//Imprimiendo los vectores desordenados, ya ordenados, después del algoritmo (opcional)
	/*cout << endl << "Vector 1 desordenado ya ordenado " << endl;
	vector1_desordenado.display();
	cout << endl << "Vector 2 desordenado ya ordenado: " << endl;
	vector2_desordenado.display();
	cout << endl << "Vector 3 desordenado ya ordenado: " << endl;
	vector3_desordenado.display();
	cout << endl << "Vector 4 desordenado ya ordenado: " << endl;
	vector4_desordenado.display();
	cout << endl << "Vector 5 desordenado ya ordenado: " << endl;
	vector5_desordenado.display();*/

    return 0;
}
