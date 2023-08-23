#include <iostream>
using namespace std;

const int SIZE = 3;
struct Student
{
    string name;
    int id;
};


void printArray(Student arr[], int size);
void changeArray(Student arr[], int size);
void printStudent(Student s);
void selectionSortStudentID(Student array[], int size);

int main(){
    Student numbers[SIZE];
    printArray(numbers,SIZE);
    changeArray(numbers,SIZE);
    printArray(numbers,SIZE);
    selectionSortStudentID(numbers,SIZE);
    printArray(numbers,SIZE);


    return 0;
}
void printArray(Student arr[], int size){
    cout<<"\n*******Students on the list*******\n";
    for (int i = 0; i<size; i++){
        printStudent(arr[i]);
    }
    cout<<endl;
}
void printStudent(Student s){
    cout<<"Name: "<<s.name<<endl;
    cout<<"  ID: "<<s.id<<endl;
}

void changeArray(Student arr[], int size){
    for (int i = 0; i<size; i++){
        cout<<"\nStudent "<<i+1<<endl;
        cout<<"Enter name: ";
        getline(cin,arr[i].name);
        cout<<"Enter id: ";
        cin>>arr[i].id;   
        cin.ignore(); 
    }
}

void selectionSortStudentID(Student array[], int size)
{
    for (int startScan = 0; startScan < (size - 1); ++startScan)
    {
        int minIndex = startScan;
        Student minValue = array[startScan];
        for (int index = startScan + 1; index < size; ++index)
        {
            if (array[index].id < minValue.id)
            {
                minValue = array[index];
                minIndex = index;
            }
        }
        array[minIndex] = array[startScan];
        array[startScan] = minValue;
    }
}

