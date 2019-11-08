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
	//Vectores ordenados pero invertidos
	Vector vector1_invertido;
	Vector vector2_invertido;
	Vector vector3_invertido;
	Vector vector4_invertido;
	Vector vector5_invertido;
	
	for(int i = 5; i > 0; i--) vector1_invertido.push_back(i);
	for(int i = 10; i > 0; i--) vector2_invertido.push_back(i);
	for(int i = 50; i > 0; i--) vector3_invertido.push_back(i);
	for(int i = 100; i > 0; i--) vector4_invertido.push_back(i);
	for(int i = 1000; i > 0; i--) vector5_invertido.push_back(i);
	
	cout << endl << "Vector 1 invertido: " << endl;
	vector1_invertido.display();
	cout << endl << "Vector 2 invertido: " << endl;
	vector2_invertido.display();
	cout << endl << "Vector 3 invertido: " << endl;
	vector3_invertido.display();
	cout <<  endl << "Vector 4 invertido: " << endl;
	vector4_invertido.display();
	cout << end << "Vector 5 invertido: " << endl;
	vector5_invertido.display();

	return 0;
	
}
