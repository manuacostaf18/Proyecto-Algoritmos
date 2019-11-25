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
void mergesort(Vec & left, Vec & right, Vec & vector){
	int nL = left.getsize();
	int nR = right.getsize();
	int i = 0, j = 0, k = 0;
	
	while(j < nL && k < nR){
		if(left.get(j) < right.get(k)){
			vector.set(i, left.get(j));
			j++;
		}
		else{
			vector.set(i, right.get(k));
			k++;
		}
		i++;
	}
	while(j < nL){
		vector.set(i, left.get(j));
		j++;
		i++;
	}
	while(k < nR){
		vector.set(i, right.get(k));
		k++;
		i++;
	}
		
}

void sort(Vec & vector){
	if(vector.getsize() <= 1) return;
	
	int mid = vector.getsize()/2;
	Vec left;
	Vec right;
	
	for(size_t j = 0; j < mid; j++){
		left.push_back(vector.get(j));
	}
	for(size_t j = 0; j < (vector.getsize() - mid); j++){
		right.push_back(vector.get(mid+j));
	}
	
	sort(left);
	sort(right);
	mergesort(left, right, vector);
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
	sort(vector1_ordenado);
	double t1_1 = gettime();
	double t1 = t1_1 - t1_0;
	cout << "Tiempo tomado ordenando al vector1_ordenado = " << t1 << endl;
	
	double t2_0 = gettime();
	sort(vector2_ordenado);
	double t2_1 = gettime();
	double t2 = t2_1 - t2_0;
	cout << "Tiempo tomado ordenando al vector2_ordenado = " << t2 << endl;
	
	double t3_0 = gettime();
	sort(vector3_ordenado);
	double t3_1 = gettime();
	double t3 = t3_1 - t3_0;
	cout << "Tiempo tomado ordenando al vector3_ordenado = " << t3 << endl;
	
	double t4_0 = gettime();
	sort(vector4_ordenado);
	double t4_1 = gettime();
	double t4 = t4_1 - t4_0;
	cout << "Tiempo tomado ordenando al vector4_ordenado = " << t4 << endl;
	
	double t5_0 = gettime();
	sort(vector5_ordenado);
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
