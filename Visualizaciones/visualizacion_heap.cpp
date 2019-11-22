
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
void heapify(Vec& vector, int n, int i){
  int largest = i;
  int l = 2*i + 1;
  int r = 2*i + 2;

  if (l < n && vector.get(l) > vector.get(largest)) largest = l;

  if (r < n && vector.get(r) > vector.get(largest)) largest = r;

  if (largest != i){
    swap (i, largest, vector);
    heapify(vector, n, largest);
  }
}

void heap_sort(Vec& vector, int n){
  for (int i = n/2-1; i>=0; i--){
    heapify(vector, n, i);
    vector.display();
  }

  for (int i = n-1; i>=0; i--){
    swap(0, i, vector);
    heapify(vector, i, 0);
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
    
    int n1 = vector1_desordenado.getsize();
    int n2 = vector2_desordenado.getsize();
    
    heap_sort(vector1_desordenado, n1);
    heap_sort(vector2_desordenado, n2);
    
    return 0;
}
