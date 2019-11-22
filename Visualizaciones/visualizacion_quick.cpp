
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

void quick_sort(Vec & vector, int low, int high){
	if(low < high){
		int pi = partition(vector, low, high);
		
		quick_sort(vector, low, pi - 1);
		quick_sort(vector, pi + 1, high);
		vector.display();
	}
}

int main(){
    srand(time(NULL));
    
	Vec vector1_desordenado;
	Vec vector2_desordenado;
	
	for(int i = 1; i < 6; i++){
        int num = 1 + rand() % (101 - 1);
        vector1_desordenado.push_back(num);
    }
    for(int i = 1; i < 11; i++){
        int num = 1 + rand() % (101 - 1);
        vector2_desordenado.push_back(num);
    }
    
   	int L1 = 0;
	int R1 = vector1_desordenado.getsize()-1;
	int L2 = 0;
	int R2 = vector2_desordenado.getsize()-1;
	
    quick_sort(vector1_desordenado, L1, R1);
    quick_sort(vector2_desordenado, L2, R2);
    
    return 0;
}
