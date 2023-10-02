#include <iostream>
#include <ctime>
#include <chrono>
void countDown(int num);
void countDown1(int num);
int main(){
    auto start = std::chrono::high_resolution_clock::now();
    countDown(2000);
    auto result1 = std::chrono::high_resolution_clock::now() - start;

    start = std::chrono::high_resolution_clock::now();
    countDown1(2000);
    auto result2 = std::chrono::high_resolution_clock::now() - start;

    long long r1 = std::chrono::duration_cast<std::chrono::microseconds>(
        result1).count();
    long long r2 = std::chrono::duration_cast<std::chrono::microseconds>(
        result2).count();
    std::cout<<"Time with loop: "<<r1<<"\n"
              <<"Time with recurtion: "<<r2<<"\n\n";

    return 0;
}

void countDown1(int num)
{ 	
   if (num == 0) // Base case
   {
      
   }
   else
   { 
      countDown1(num-1); 
   }
}
void countDown(int num)
{ 	
    while (num > 0)
    {
        //cout << num << ". . .";
        --num;
    }
    //cout << "Blastoff!";
}


