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
	sort(vector1_invertido);
	double t1_1 = gettime();
	double t1 = t1_1 - t1_0;
	cout << "Tiempo tomado ordenando al vector1_invertido = " << t1 << endl;
	
	double t2_0 = gettime();
	sort(vector2_invertido);
	double t2_1 = gettime();
	double t2 = t2_1 - t2_0;
	cout << "Tiempo tomado ordenando al vector2_invertido = " << t2 << endl;
	
	double t3_0 = gettime();
	sort(vector3_invertido);
	double t3_1 = gettime();
	double t3 = t3_1 - t3_0;
	cout << "Tiempo tomado ordenando al vector3_invertido = " << t3 << endl;
	
	double t4_0 = gettime();
	sort(vector4_invertido);
	double t4_1 = gettime();
	double t4 = t4_1 - t4_0;
	cout << "Tiempo tomado ordenando al vector4_invertido = " << t4 << endl;
	
	double t5_0 = gettime();
	sort(vector5_invertido);
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
