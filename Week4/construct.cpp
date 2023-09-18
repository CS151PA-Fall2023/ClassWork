#include <iostream>
using namespace std;

class Parent {
public:
    Parent(int j, int k){
        x=j;
        y=k;
    };
    Parent(){
        x=0;
        y=0;
    };
    void getXY(){
        cout<<x <<" "<< y;
    }

private:
    int x, y;
};

class Child : public Parent
{
public: 
    Child(int a) //: Parent(a, a*a)
    {
        z = a;
    }
    void getValues(){
        getXY();
        cout<<" "<<z<<endl;
    }

private:
    int z;
};  

int main()
{
    Child ch(2);
    ch.getValues();

}
