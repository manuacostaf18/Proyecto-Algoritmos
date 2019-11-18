#include "vec.hpp"
#include <iostream>
using namespace std;

const int INITIAL_CAPACITY = 50;

void Vec::expandCapacity(){
	int *old = array;
	capacity *= 2;
	array = new int[capacity];
	for(int i = 0; i < count; i++){
		array[i] = old[i];
	}
	delete [] old;
}

Vec::Vec(){ //Inicializa un vector de capacidad 50, vacío, con todos sus elementos en 0.
	capacity = INITIAL_CAPACITY;
	array = new int[capacity];
	for(int i = 0; i<capacity; ++i){
		array[i] = 0;
	}
	count = 0;
	cout << "Vector created." << endl;
}

Vec::~Vec(){ //Destruye la instancia de vector creada. 
	delete [] array;
	cout << "Instance destroyed." << endl;
}

int Vec::getsize(){ //Retorna el número de elementos del vector. 
	return count;
}

bool Vec::empty(){ //Retorna verdadero si el vector está vacío, y falso en caso contrario.
	return count == 0;
}

void Vec::set(int pos, int val){ //Ingresa el valor val en la posición pos. Si esa posición está vacía, lo ingresa, si no, cambia el valor anterior. 
	if(array[pos] == 0) count++;
	array[pos] = val;
}

void Vec::push_back(int x){
	if(count == capacity) expandCapacity();
	array[count] = x;
	count++;
}

void Vec::pop_back(){
	cout << "Popping " << array[count-1];
	array[count-1] = 0;
	count--;
}

int Vec::get(int pos){
	return array[pos];
}

int Vec::getfront(){
	return array[0];
}

int Vec::getlast(){
	return array[count-1];
}

void Vec::display(){
	for(int i = 0; i < count; i++){
		cout << array[i] << " ";
	}
	cout << endl;
}

