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
	
	//Creando los 5 vectores ordenados pero invertidos, de tamaños diferentes
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
	
	//Imprimiendo los vectores invertidos (opcional)
	/*cout << endl << "Vector 1 invertido: " << endl;
	vector1_invertido.display();
	cout << endl << "Vector 2 invertido: " << endl;
	vector2_invertido.display();
	cout << endl << "Vector 3 invertido: " << endl;
	vector3_invertido.display();
	cout <<  endl << "Vector 4 invertido: " << endl;
	vector4_invertido.display();
	cout << end << "Vector 5 invertido: " << endl;
	vector5_invertido.display();*/
	
	//Probando el algoritmo con cada uno de los 5 vectores invertidos. 
	double t1_0 = gettime();
	Vector vector1_invertido_end = //Poner algoritmo acá, con los argumentos necesarios, para ordenar el vector1_invertido.
	double t1_1 = gettime();
	double t1 = t1_1 - t1_0;
	cout << "Tiempo tomado ordenando al vector1_invertido = " << t1 << endl;
	
	double t2_0 = gettime();
	Vector vector2_invertido_end = //Poner algoritmo acá, con los argumentos necesarios, para ordenar el vector2_invertido.
	double t2_1 = gettime();
	double t2 = t2_1 - t2_0;
	cout << "Tiempo tomado ordenando al vector2_invertido = " << t2 << endl;
	
	double t3_0 = gettime();
	Vector vector3_invertido_end = //Poner algoritmo acá, con los argumentos necesarios, para ordenar el vector3_ivertido.
	double t3_1 = gettime();
	double t3 = t3_1 - t3_0;
	cout << "Tiempo tomado ordenando al vector3_invertido = " << t3 << endl;
	
	double t4_0 = gettime();
	Vector vector4_invertido_end = //Poner algoritmo acá, con los argumentos necesarios, para ordenar el vector4_invertido.
	double t4_1 = gettime();
	double t4 = t4_1 - t4_0;
	cout << "Tiempo tomado ordenando al vector4_invertido = " << t4 << endl;
	
	double t5_0 = gettime();
	Vector vector5_invertido_end = //Poner algoritmo acá, con los argumentos necesarios, para ordenar el vector5_invertido.
	double t5_1 = gettime();
	double t5 = t5_1 - t5_0;
	cout << "Tiempo tomado ordenando al vector5_invertido = " << t5 << endl;
	
	//Imprimiendo los vectores invertidos, ya ordenados, después del algoritmo (opcional)
	/*cout << endl << "Vector 1 invertido ya ordenado " << endl;
	vector1_invertido_end.display();
	cout << endl << "Vector 2 invertido ya ordenado: " << endl;
	vector2_invertido_end.display();
	cout << endl << "Vector 3 invertido ya ordenado: " << endl;
	vector3_invertido_end.display();
	cout <<  endl << "Vector 4 invertido ya ordenado: " << endl;
	vector4_invertido_end.display();
	cout << end << "Vector 5 invertido ya ordenado: " << endl;
	vector5_invertido_end.display();*/


	return 0;
	
}
