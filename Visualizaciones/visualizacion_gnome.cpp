
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
void gnome_sort(Vec& vector, int sz){
	int index = 0;

  while(index < sz){
    if(index == 0) index++;
    if (vector.get(index) >= vector.get(index-1)) index++;
    else{
      swap(index, index-1, vector);
      vector.display();
      index--;
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
    
    int szvec1 = vector1_desordenado.getsize();
    int szvec2 = vector2_desordenado.getsize();
    
    gnome_sort(vector1_desordenado, szvec1);
    gnome_sort(vector2_desordenado, szvec2);
    
    return 0;
}
