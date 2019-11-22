
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
void selection_sort(Vec& vector){
	for(int i = 0; i < vector.getsize()-1; ++i){
		int min_id = i;
		for(int j = i+1; j < vector.getsize(); ++j){
			if(vector.get(j) < vector.get(min_id)){
				min_id = j;
			}
		}
		swap(i, min_id, vector);
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
    
    selection_sort(vector1_desordenado);
    selection_sort(vector2_desordenado);
    
    return 0;
}
