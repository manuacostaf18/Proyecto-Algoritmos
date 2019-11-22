
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
void bubble_sort(Vec& vector){
	bool swap_used = true;
	while(swap_used){
		swap_used = false;
		for(int i = 0; i < vector.getsize()-1; ++i){
			if(vector.get(i) > vector.get(i+1)){
				swap(i, i+1, vector);
				vector.display();
				swap_used = true;
			}
		}
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
    
    bubble_sort(vector1_desordenado);
    bubble_sort(vector2_desordenado);
    
    return 0;
}
