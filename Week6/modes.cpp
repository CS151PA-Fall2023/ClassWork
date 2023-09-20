#include <iostream>
#include <fstream>
#include <iomanip>

int main(){
    std::fstream file("test.txt", std::ios::out);
    file<<std::setw(10)<<std::left<<"Line"<<std::setw(5)<<std::right<<"1\n";
    file << "New Line"<<std::endl;
    file.close();
    return 0;
}