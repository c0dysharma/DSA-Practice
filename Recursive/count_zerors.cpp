#include <iostream>

int countZeros(int x){
    // base case
    if(x == 0)
        return 1;
    if(x<10)
        return 0; 
    // recursive call
        // dividing by 10 removes last digit
    int smallerOutput = countZeros(x/10);
    //smaller calculation | modulo division gives last digit
    return (x%10 == 0) ? smallerOutput+1 : smallerOutput;

}

int main(void){
    std::cout << countZeros(100) << std::endl;
    return 0;
}