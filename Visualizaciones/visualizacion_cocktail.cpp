
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
void cocktail_sort(Vec& vector, int n){
  bool swapped = true;
  int start = 0;
  int end = n-1;

  while(swapped){
  	vector.display();
  	
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
    
    int n1 = vector1_desordenado.getsize();
   	int n2 = vector2_desordenado.getsize();
   	 
    cocktail_sort(vector1_desordenado, n1);
    cocktail_sort(vector2_desordenado, n2);
    
    return 0;
}
