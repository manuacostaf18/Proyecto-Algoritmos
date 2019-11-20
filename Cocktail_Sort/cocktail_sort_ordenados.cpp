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
void CocktailSort(Vec& vector, int n){
  bool swapped = true;
  int start = 0;
  int end = n-1;

  while(swapped){
    swapped = false;

    for (int i = start; i < end; i++){
      if(vector.get(i) > vector.get(i+1)){
        swap(i, i+1, vector);
        swapped = true;
      }
    }

    if (!swapped) break;
    swapped = false;
    end--;

    for(int i = end-1; i >= start; i--){
      if(vector.get(i) > vector.get(i+1)){
        swap(i, i+1, vector);
        swapped = true;
      }
    }
    start++;
  }
}

int main(){
  srand(time(NULL));

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
  int n1 = vector1_ordenado.getsize();
  double t1_0 = gettime();
	CocktailSort(vector1_ordenado, n1);
	double t1_1 = gettime();
	double t1 = t1_1 - t1_0;
	cout << "Tiempo tomado ordenando al vector1_ordenado = " << t1 << endl;

  int n2 = vector2_ordenado.getsize();
	double t2_0 = gettime();
	CocktailSort(vector2_ordenado, n2);
	double t2_1 = gettime();
	double t2 = t2_1 - t2_0;
	cout << "Tiempo tomado ordenando al vector2_ordenado = " << t2 << endl;

  int n3 = vector3_ordenado.getsize();
	double t3_0 = gettime();
	CocktailSort(vector3_ordenado, n3);
	double t3_1 = gettime();
	double t3 = t3_1 - t3_0;
	cout << "Tiempo tomado ordenando al vector3_ordenado = " << t3 << endl;

  int n4 = vector4_ordenado.getsize();
	double t4_0 = gettime();
	CocktailSort(vector4_ordenado, n4);
	double t4_1 = gettime();
	double t4 = t4_1 - t4_0;
	cout << "Tiempo tomado ordenando al vector4_ordenado = " << t4 << endl;

  int n5 = vector5_ordenado.getsize();
	double t5_0 = gettime();
	CocktailSort(vector5_ordenado, n5);
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
