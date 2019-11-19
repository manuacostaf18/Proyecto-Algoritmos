#include <iostream>
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

	//Creando los 5 vectores ordenados pero invertidos, de tamaños diferentes
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
  int n1 = vector1_invertido.getsize();
  double t1_0 = gettime();
	heap_sort(vector1_invertido, n1);
	double t1_1 = gettime();
	double t1 = t1_1 - t1_0;
	cout << "Tiempo tomado ordenando al vector1_invertido = " << t1 << endl;

  int n2 = vector2_invertido.getsize();
  double t2_0 = gettime();
	heap_sort(vector2_invertido, n2);
	double t2_1 = gettime();
	double t2 = t2_1 - t2_0;
	cout << "Tiempo tomado ordenando al vector2_invertido = " << t2 << endl;

  int n3 = vector3_invertido.getsize();
  double t3_0 = gettime();
  heap_sort(vector3_invertido, n3);
	double t3_1 = gettime();
	double t3 = t3_1 - t3_0;
	cout << "Tiempo tomado ordenando al vector3_invertido = " << t3 << endl;

  int n4 = vector4_invertido.getsize();
  double t4_0 = gettime();
  heap_sort(vector4_invertido, n4);
	double t4_1 = gettime();
	double t4 = t4_1 - t4_0;
	cout << "Tiempo tomado ordenando al vector4_invertido = " << t4 << endl;

  int n5 = vector5_invertido.getsize();
	double t5_0 = gettime();
  heap_sort(vector5_invertido, n5);
	double t5_1 = gettime();
	double t5 = t5_1 - t5_0;
	cout << "Tiempo tomado ordenando al vector5_invertido = " << t5 << endl;

	//Imprimiendo los vectores invertidos, ya ordenados, después del algoritmo (opcional)
	/*cout << endl << "Vector 1 invertido ya ordenado " << endl;
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
