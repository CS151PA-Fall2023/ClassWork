#include <iostream>
#include <fstream>

using namespace std;

int main(){
    //creat a file for writing
    //ofstream outputFile("something.txt");
    ofstream outputFile;
    outputFile.open("something.txt");
    if (!outputFile){
        cout<<"Error opening file\n";
        exit(1);
    }
    //write something
    outputFile<<"Just writing somthing\n";
    outputFile<<"And some more\n";
    //close file
    outputFile.close();
    //open file for reading
    ifstream file("something.txt");
    //read it to the console
    string line;
    while(getline(file,line)){
        //getline(file,line);
        cout<<line<<endl;
    }
    //close file
    file.close();

    return 0;
}