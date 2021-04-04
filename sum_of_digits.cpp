/*
Chapter Assignment
Problem Statement: Sum of digits (recursive)
Problem Level: EASY
Problem Description:
Write a recursive function that returns the sum of the digits of a given integer.
Input format :
Integer N

Output format :
Sum of digits of N

Constraints :
0 <= N <= 10^9

Sample Input 1 :
12345

Sample Output 1 :
15

Sample Input 2 :
9

Sample Output 2 :
9
*/
#include <iostream>

int sumOfDigits(int i){
    // base case
    if(i<=9)
        return i;
    // recursive call xxxx|x
    int smallerOutput = sumOfDigits(i/10);
    // smallcalculation
    return (smallerOutput + (i%10));
    
}

int main(void){
    int i;
    std::cin >> i;
    std::cout << sumOfDigits(i) << std::endl;
}