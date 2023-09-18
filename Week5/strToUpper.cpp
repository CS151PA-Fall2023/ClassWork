#include <iostream>
#include <string>
using namespace std;

class myString:public string
{
public:
    myString(string s):string(s)
    {
    }

    void allUpper()
    {
        for (unsigned int i = 0; i < size(); ++i)
        {
            (*this)[i]=toupper((*this)[i]);
        }
    }
};

int main()
{
    myString str("I like to code.");
    cout <<str<<endl;
    str.allUpper();
    cout <<str<<endl;
    cout<<"the size of this string is "<<str.size()<<endl;
    return 0;
}
