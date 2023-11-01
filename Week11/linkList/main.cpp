#include <iostream>
#include "linkList.h"


int main()
{
    LinkedList myList;
    myList.addR(-3);
    myList.addR(5);
    myList.addR(7);
    std::cout<<myList.toStringR()<<std::endl;

}