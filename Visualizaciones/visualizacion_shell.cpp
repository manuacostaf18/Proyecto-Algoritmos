
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
void shell_sort(Vec & vector){
	for(int gapSize = vector.getsize()/2; gapSize > 0; gapSize /= 2){
		for(int currentIndex = gapSize; currentIndex < vector.getsize(); currentIndex++){
			int currentIndexCopy = currentIndex;
			int item = vector.get(currentIndex);
			while(currentIndexCopy >= gapSize && vector.get(currentIndexCopy - gapSize) > item){
				vector.set(currentIndexCopy, vector.get(currentIndexCopy - gapSize));
				currentIndexCopy -= gapSize;
			}
		vector.set(currentIndexCopy, item);
		vector.display();
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
	
    shell_sort(vector1_desordenado);
    shell_sort(vector2_desordenado);
    
    return 0;
}
