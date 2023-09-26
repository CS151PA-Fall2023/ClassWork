#include <iostream>
#include <fstream>
#include <iomanip>

int main()
{
    std::fstream outFile("myfile", std::ios::binary | std::ios::out);
    double d[2] = {12.3, 34.5};
    outFile.write(reinterpret_cast<char*>(d), sizeof(d));//2*sizeof(double)
    outFile.close();

    std::fstream inFile("myfile", std::ios::binary | std::ios::in);
    const int DSIZE = 10;
    double data[DSIZE];
    inFile.read(reinterpret_cast<char*>(data), sizeof(double) * 2);
    std::cout<<std::fixed<<std::setprecision(2)<<std::endl;
    std::cout<<data[0]<<" "<<data[1]<<std::endl;
    inFile.close();
}