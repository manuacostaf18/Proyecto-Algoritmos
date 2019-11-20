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
			swap(vector.get(i), vector.get(j), vector);
		}
	}
	
	swap(vector.get(i+1), vector.get(high), vector);
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
	double t1_0 = gettime();
	int L1 = 0;
	int R1 = vector1_invertido.getsize()-1;
	quicksort(vector1_invertido, L1, R1);
	double t1_1 = gettime();
	double t1 = t1_1 - t1_0;
	cout << "Tiempo tomado ordenando al vector1_invertido = " << t1 << endl;
	
	double t2_0 = gettime();
	int L2 = 0;
	int R2 = vector2_invertido.getsize()-1;
	quicksort(vector2_invertido, L2, R2);
	double t2_1 = gettime();
	double t2 = t2_1 - t2_0;
	cout << "Tiempo tomado ordenando al vector2_invertido = " << t2 << endl;
	
	double t3_0 = gettime();
	int L3 = 0;
	int R3 = vector3_invertido.getsize()-1;
	quicksort(vector3_invertido, L3, R3);
	double t3_1 = gettime();
	double t3 = t3_1 - t3_0;
	cout << "Tiempo tomado ordenando al vector3_invertido = " << t3 << endl;
	
	double t4_0 = gettime();
	int L4 = 0;
	int R4 = vector4_invertido.getsize()-1;
	quicksort(vector4_invertido, L4, R4);
	double t4_1 = gettime();
	double t4 = t4_1 - t4_0;
	cout << "Tiempo tomado ordenando al vector4_invertido = " << t4 << endl;
	
	double t5_0 = gettime();
	int L5 = 0;
	int R5 = vector5_invertido.getsize()-1;
	quicksort(vector5_invertido, L5, R5);
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
