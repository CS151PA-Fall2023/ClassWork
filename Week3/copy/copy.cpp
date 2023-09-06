#include "copy.h"
NumberArray:: NumberArray(int size, double initValue)
{   
    this->arraySize=size;
    arr = new double[arraySize];
    for (int i = 0; i <arraySize; i++){
        //arr[i]=initValue;
        *(arr + i) = initValue;
    }

}

NumberArray::NumberArray(const NumberArray & old)
{
    this->arraySize=old.arraySize;
    this->arr = new double[arraySize];
    for (int i = 0; i <arraySize; i++){
        //arr[i]=old.arr[i];
        *(arr + i) = *(old.arr + i);
    }

}

void NumberArray::print() const
{
    for (int i = 0; i <arraySize; i++){
        //arr[i]=initValue;
        cout<<*(arr + i)<<" ";
    }
    cout<<endl;
}

void NumberArray::setValue(double value)
{
    for (int i = 0; i <arraySize; i++){
        //arr[i]=value;
        *(arr + i) = value;
    }
}
