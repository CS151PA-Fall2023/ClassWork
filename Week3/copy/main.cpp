#include <iostream>
#include "copy.h"
using namespace std;

int main(){
    NumberArray arr1;
    arr1.print();

    NumberArray arr2(5, 7.3);
    arr2.print();

    NumberArray arr3 = arr2;
    arr3.print();

    arr3.setValue(2.2);
    arr3.print();


    return 0;
}