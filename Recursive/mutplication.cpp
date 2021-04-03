#include <iostream>

int multiply(int m, int n){
    //base case
    if(n ==0)
        return 0;
    //recursive function
    int smallOutput = multiply(m,n-1);
    //small calculation
    return smallOutput+m;
}

int main(void){
    int m = multiply(1,5);
    std::cout << m << std::endl;
    return 0;
}