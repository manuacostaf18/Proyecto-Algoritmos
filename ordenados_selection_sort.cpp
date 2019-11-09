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

void swap(int i, int j, Vector& vector){
  int temp = vector.get(i);
  vector.set(i, vector.get(j));
  vector.set(j, temp);
}

//Algoritmo
void selection_sort(Vector& vector){
	for(int i = 0; i < vector.getsize()-1; ++i){
		int min_id = i;
		for(int j = i+1; j < vector.getsize(); ++j){
			if(vector.get(j) < vector.get(min_id)){
				min_id = j;
			}
		}
		swap(i, min_id, vector);
	}
}

int main(){
	
	//Creando los 5 vectores ordenados, de tamaños diferentes 
	Vector vector1_ordenado;
	Vector vector2_ordenado;
	Vector vector3_ordenado;
	Vector vector4_ordenado;
	Vector vector5_ordenado;
	
	for(int i = 1; i < 6; i++) vector1_ordenado.push_back(i);
	for(int i = 1; i < 11; i++) vector2_ordenado.push_back(i);
	for(int i = 1; i < 51; i++) vector3_ordenado.push_back(i);
	for(int i = 1; i < 101; i++) vector4_ordenado.push_back(i);
	for(int i = 1; i < 1001; i++) vector5_ordenado.push_back(i);
	
	//Imprimiendo los vectores ordenados (opcional)
	/*cout << "Vector 1 ordenado: " << endl;
	vector1_ordenado.display();
	cout << endl << "Vector 2 ordenado: " << endl;
	vector2_ordenado.display();
	cout << endl << "Vector 3 ordenado: " << endl;
	vector3_ordenado.display();
	cout << endl << "Vector 4 ordenado: " << endl;
	vector4_ordenado.display();
	cout << endl << "Vector 5 ordenado: " << endl;
	vector5_ordenado.display();*/

	//Probando el algoritmo con cada uno de los 5 vectores ordenados. 
	double t1_0 = gettime();
	selection_sort(vector1_ordenado);
	double t1_1 = gettime();
	double t1 = t1_1 - t1_0;
	cout << "Tiempo tomado ordenando al vector1_ordenado = " << t1 << endl;
	
	double t2_0 = gettime();
	selection_sort(vector2_ordenado);
	double t2_1 = gettime();
	double t2 = t2_1 - t2_0;
	cout << "Tiempo tomado ordenando al vector2_ordenado = " << t2 << endl;
	
	double t3_0 = gettime();
	selection_sort(vector3_ordenado);
	double t3_1 = gettime();
	double t3 = t3_1 - t3_0;
	cout << "Tiempo tomado ordenando al vector3_ordenado = " << t3 << endl;
	
	double t4_0 = gettime();
	selection_sort(vector4_ordenado);
	double t4_1 = gettime();
	double t4 = t4_1 - t4_0;
	cout << "Tiempo tomado ordenando al vector4_ordenado = " << t4 << endl;
	
	double t5_0 = gettime();
	selection_sort(vector5_ordenado);
	double t5_1 = gettime();
	double t5 = t5_1 - t5_0;
	cout << "Tiempo tomado ordenando al vector5_ordenado = " << t5 << endl;
	
	//Imprimiendo los vectores ordenados, después del algoritmo (opcional)
	/*cout << "Vector 1 ordenado: " << endl;
	vector1_ordenado.display();
	cout << endl << "Vector 2 ordenado: " << endl;
	vector2_ordenado.display();
	cout << endl << "Vector 3 ordenado: " << endl;
	vector3_ordenado.display();
	cout << endl << "Vector 4 ordenado: " << endl;
	vector4_ordenado.display();
	cout << endl << "Vector 5 ordenado: " << endl;
	vector5_ordenado.display();*/

	return 0;
	
}
