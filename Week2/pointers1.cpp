#include <iostream>
using namespace std;

int main(){
    int arr[5]={1,2,3,4,5};
    int * intp;
    intp = arr;


    cout<<*intp<<endl;
    (*intp)++;//*intp = *intp +1;
    cout<<*intp<<endl;
    intp++;//intp = intp +1*sizeof(int);
    cout<<*intp<<endl;


    return 0;
}