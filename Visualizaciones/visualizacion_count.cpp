
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "vec.hpp"
#include <set>
#include <sys/time.h>
#include <map>
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
void count_sort(Vec& vector){
  map<int, int> freq;

  for(int i = 0; i < vector.getsize(); i++){
    freq[vector.get(i)]++;
  }
  int i = 0;
  for(auto it: freq){
    while(it.second--){
      vector.set(i++, it.first);
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
   	 
    count_sort(vector1_desordenado);
    count_sort(vector2_desordenado);
    
    return 0;
}
