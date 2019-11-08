#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main(){
    srand(time(NULL));
    
    for(int i = 1; i < 11; i++){
        int num = 1 + rand() % (11 - 1);
        cout << num<< " ";
    }
    
    return 0;
}
