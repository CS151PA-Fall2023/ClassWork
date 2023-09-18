#include <iostream>
using namespace std;

class A
{
     public:
          int aaa;
     protected:
          int aa;
     private:
          int a;
};

class B:private A
{
     public:
          int bbb;
          int getA(){return aaa;}
     protected:
          int bb;
     private:
          int b;
};

int main()
{
     A objectA;
     //objectA.a = 5;
     //objectA.aa = 55;
     objectA.aaa=555;
     B objectB;
    //  objectB.b=3;
    //  objectB.bb=33;
     //objectB.bbb=333;
     //objectB.a=8;
     cout<<objectB.getA()<<endl;
     //objectB.aa=88;
     //objectB.aaa=888;

     return 0;

}