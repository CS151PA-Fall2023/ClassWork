#include <iostream>
using namespace std;

class Person
{
public:
     virtual ~Person()
    {
        cout << "Deleting a person.\n";
    }
};

class Student : public Person
{
public:
    virtual ~Student()
    {
        cout << "Deleting a student.\n";
    }
};

int main()
{
    Person *p = new Student();
    delete p; // Which destructor will get triggered?
}
