#include <iostream>
#include <cstring>

int main(int argc, char *argv[]) 
{
    char str1[20];
    char str2[10];
    strncpy(str1, argv[1], 10);
    strncpy(str2, argv[2], 10);
    std::cout << str1<<"\n";   // prints: Good Morning!
    std::cout << str2<<"\n";    
    strcat(str1, str2);
    std::cout << str1<<"\n";   // prints: Good Morning!
    std::cout << str2<<"\n";  
    return 0;
}