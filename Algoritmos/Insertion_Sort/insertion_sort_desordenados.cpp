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
void insertion_sort(Vec& vector){
	for(int i = 1; i < vector.getsize(); ++i){
		int a = i;
		int b = i-1;
		while(vector.get(b) > vector.get(a)){
			swap(a, b, vector);
      			a--;
			b = a-1;
		}
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
	double t1_0 = gettime();
	insertion_sort(vector1_desordenado);
	double t1_1 = gettime();
	double t1 = t1_1 - t1_0;
	cout << "Tiempo tomado ordenando al vector1_desordenado = " << t1 << endl;

	double t2_0 = gettime();
	insertion_sort(vector2_desordenado);
	double t2_1 = gettime();
	double t2 = t2_1 - t2_0;
	cout << "Tiempo tomado ordenando al vector2_desordenado = " << t2 << endl;

	double t3_0 = gettime();
	insertion_sort(vector3_desordenado);
	double t3_1 = gettime();
	double t3 = t3_1 - t3_0;
	cout << "Tiempo tomado ordenando al vector3_desordenado = " << t3 << endl;

	double t4_0 = gettime();
	insertion_sort(vector4_desordenado);
	double t4_1 = gettime();
	double t4 = t4_1 - t4_0;
	cout << "Tiempo tomado ordenando al vector4_desordenado = " << t4 << endl;

	double t5_0 = gettime();
	insertion_sort(vector5_desordenado);
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
