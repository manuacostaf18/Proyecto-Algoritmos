#include "vec.hpp"
#include <iostream>
using namespace std;

int main(){
	Vec mivec = Vec();
	cout << "Tamaño = " << mivec.getsize() << endl;
	cout << "¿Vacío? = " << mivec.empty() << endl;
	mivec.set(2, 3);
	cout << "¿Vacío? = " << mivec.empty() << endl;
	mivec.push_back(5);
	cout << mivec.get(2) << endl;
	cout << "¿Vacío? = " << mivec.empty() << endl;
	mivec.display();

	Vec vector = Vec();
	for(int i = 0; i < 11; i++){
		vector.push_back(i);
	}
	vector.display();
	return 0;
}
