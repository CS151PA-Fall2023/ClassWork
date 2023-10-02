#include <iostream>
int sumOfDigitsOf(int n);
int digitalRoot(int num);
int main(){
    std::cout<<"Sum of digits in 12345 is "
        <<sumOfDigitsOf(12345)<<std::endl;
    std::cout<<"Digital root of 12345 is "
        <<digitalRoot(12345)<<std::endl;

}
int digitalRoot(int num){
    if (num/10==0){
        return num;
    }else{
        return digitalRoot(sumOfDigitsOf(num));
    }
}

int sumOfDigitsOf(int n)
{
    if (n/10==0){//check if only one digit
        return n%10;//return this digit
    } else {
        return n%10 + sumOfDigitsOf(n/10);
    }
    // int result = 0;
    // while (n > 0)
    // {
    //     result += (n % 10);
    //     n /= 10;
    // }
    // return result;
}
