#include <iostream>
using namespace std;

int main(){
    int a=7;
    int *iptr = nullptr;
    iptr = new int[100];

    cout<<"Adress of a "<<&a<<endl;
    cout<<"Adress of iptr "<< &iptr<<endl;
    cout<<"Adress of array[0] "<< iptr <<endl;
    cout<<"Adress of array[1] "<< iptr + 1 <<endl;
    for (int i = 0; i < 100; ++i)
        iptr[i] = 1;

    delete [] iptr;
    return 0;
}