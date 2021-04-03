#include <iostream>

int multiply(int m, int n){
    if(m==0 || n ==0)
        return 0;
    if(m==1 || n==1){
        return (m==1) ? n :m;
    }
    
    int smallOutput = multiply(m,n-1);
    return smallOutput+m;
}

int main(void){
    int m = multiply(5,9);
    std::cout << m << std::endl;
    return 0;
}