
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
void mergesort(Vec & left, Vec & right, Vec & vector){
	int nL = left.getsize();
	int nR = right.getsize();
	int i = 0, j = 0, k = 0;
	
	while(j < nL && k < nR){
		if(left.get(j) < right.get(k)){
			vector.set(i, left.get(j));
			j++;
		}
		else{
			vector.set(i, right.get(k));
			k++;
		}
		i++;
	}
	while(j < nL){
		vector.set(i, left.get(j));
		j++;
		i++;
	}
	while(k < nR){
		vector.set(i, right.get(k));
		k++;
		i++;
	}
		
}

void sort(Vec & vector){
	if(vector.getsize() <= 1) return;
	
	int mid = vector.getsize()/2;
	Vec left;
	Vec right;
	
	for(size_t j = 0; j < mid; j++){
		left.push_back(vector.get(j));
	}
	for(size_t j = 0; j < (vector.getsize() - mid); j++){
		right.push_back(vector.get(mid+j));
	}
	
	sort(left);
	sort(right);
	mergesort(left, right, vector);
	
	vector.display();
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
    
    sort(vector1_desordenado);
    sort(vector2_desordenado);
    
    return 0;
}
