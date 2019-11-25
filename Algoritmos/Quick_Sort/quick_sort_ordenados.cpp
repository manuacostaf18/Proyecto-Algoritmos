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
int partition(Vec & vector, int low, int high){
	int pivot = vector.get(high);
	int i = (low -1);

	for(int j = low; j <= high - 1; j++){
		if(vector.get(j) < pivot){
			i++;
			swap(i, j, vector);
		}
	}

	swap(i+1, high, vector);
	return (i+1);
}

void quicksort(Vec & vector, int low, int high){
	if(low < high){
		int pi = partition(vector, low, high);

		quicksort(vector, low, pi - 1);
		quicksort(vector, pi + 1, high);
	}
}

int main(){

	//Creando los 5 vectores ordenados, de tamaños diferentes
	Vec vector1_ordenado;
	Vec vector2_ordenado;
	Vec vector3_ordenado;
	Vec vector4_ordenado;
	Vec vector5_ordenado;

	for(int i = 1; i < 6; i++) vector1_ordenado.push_back(i);
	for(int i = 1; i < 11; i++) vector2_ordenado.push_back(i);
	for(int i = 1; i < 51; i++) vector3_ordenado.push_back(i);
	for(int i = 1; i < 101; i++) vector4_ordenado.push_back(i);
	for(int i = 1; i < 1001; i++) vector5_ordenado.push_back(i);

	//Imprimiendo los vectores ordenados (opcional)
	cout << "Vector 1 ordenado: " << endl;
	vector1_ordenado.display();
	cout << endl << "Vector 2 ordenado: " << endl;
	vector2_ordenado.display();
	/*cout << endl << "Vector 3 ordenado: " << endl;
	vector3_ordenado.display();
	cout << endl << "Vector 4 ordenado: " << endl;
	vector4_ordenado.display();
	cout << endl << "Vector 5 ordenado: " << endl;
	vector5_ordenado.display();*/

	//Probando el algoritmo con cada uno de los 5 vectores ordenados.
	double t1_0 = gettime();
	int L1 = 0;
	int R1 = vector1_ordenado.getsize()-1;
	quicksort(vector1_ordenado, L1, R1);
	double t1_1 = gettime();
	double t1 = t1_1 - t1_0;
	cout << "Tiempo tomado ordenando al vector1_ordenado = " << t1 << endl;

	double t2_0 = gettime();
	int L2 = 0;
	int R2 = vector2_ordenado.getsize()-1;
	quicksort(vector2_ordenado, L2, R2);
	double t2_1 = gettime();
	double t2 = t2_1 - t2_0;
	cout << "Tiempo tomado ordenando al vector2_ordenado = " << t2 << endl;

	double t3_0 = gettime();
	int L3 = 0;
	int R3 = vector3_ordenado.getsize()-1;
	quicksort(vector3_ordenado, L3, R3);
	double t3_1 = gettime();
	double t3 = t3_1 - t3_0;
	cout << "Tiempo tomado ordenando al vector3_ordenado = " << t3 << endl;

	double t4_0 = gettime();
	int L4 = 0;
	int R4 = vector4_ordenado.getsize()-1;
	quicksort(vector4_ordenado, L4, R4);
	double t4_1 = gettime();
	double t4 = t4_1 - t4_0;
	cout << "Tiempo tomado ordenando al vector4_ordenado = " << t4 << endl;

	double t5_0 = gettime();
	int L5 = 0;
	int R5 = vector5_ordenado.getsize()-1;
	quicksort(vector5_ordenado, L5, R5);
	double t5_1 = gettime();
	double t5 = t5_1 - t5_0;
	cout << "Tiempo tomado ordenando al vector5_ordenado = " << t5 << endl;

	//Imprimiendo los vectores ordenados, después del algoritmo (opcional)
	cout << "Vector 1 ordenado: " << endl;
	vector1_ordenado.display();
	cout << endl << "Vector 2 ordenado: " << endl;
	vector2_ordenado.display();
	/*cout << endl << "Vector 3 ordenado: " << endl;
	vector3_ordenado.display();
	cout << endl << "Vector 4 ordenado: " << endl;
	vector4_ordenado.display();
	cout << endl << "Vector 5 ordenado: " << endl;
	vector5_ordenado.display();*/

	return 0;

}
