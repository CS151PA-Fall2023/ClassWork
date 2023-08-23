#include <iostream>
using namespace std;

const int SIZE = 5;

void printArray(int arr[], int size);
void changeArray(int arr[], int size);

int main(){
    int numbers[SIZE];
    printArray(numbers,SIZE);
    changeArray(numbers,SIZE);
    printArray(numbers,SIZE);

    char word[]="I like NIC";
    cout<<word<<endl;
    word[6]='\0';
    cout<<word<<endl;
    cout<<word+7<<endl;
    return 0;
}
void printArray(int arr[], int size){
    for (int i = 0; i<size; i++){
        cout<<arr[i]<< " ";
    }
    cout<<endl;
}

void changeArray(int arr[], int size){
    for (int i = 0; i<size; i++){
        arr[i]= i+1;
    }
}
