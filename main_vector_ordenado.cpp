#include <iostream>
#include "vec.hpp"
#include <set>
#include <sys/time.h>
using namespace std;

double gettime(){
  struct timeval tp;
  gettimeofday(&tp, NULL);
  return tp.tv_sec + tp.tv_usec/(double)1.0e6;
}

/*

PONER ACÁ EL CÓDIGO DEL ALGORITMO CORRESPONDIENTE

*/

int main(){
	//Vectores ordenados 
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
	
	cout << "Vector 1 ordenado: " << endl;
	vector1_ordenado.display();
	cout << endl << "Vector 2 ordenado: " << endl;
	vector2_ordenado.display();
	cout << endl << "Vector 3 ordenado: " << endl;
	vector3_ordenado.display();
	cout << endl << "Vector 4 ordenado: " << endl;
	vector4_ordenado.display();
	cout << endl << "Vector 5 ordenado: " << endl;
	vector5_ordenado.display();

	
	
	return 0;
	
}
