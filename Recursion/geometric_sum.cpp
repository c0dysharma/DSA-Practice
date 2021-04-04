/*
Chapter Assignment
Problem Statement: Geometric Sum
Problem Level: MEDIUM
Problem Description:
Given k, find the geometric sum i.e.
1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k)

using recursion.
Input format :
Integer k

Output format :
Geometric sum

Constraints :
0 <= k <= 1000

Sample Input 1 :
3

Sample Output 1 :
1.875

Sample Input 2 :
4

Sample Output 2 :
1.93750
*/

#include <iostream>
#include <cmath>

double gsum(double k){
    // base case
    if(k == 0)
        return 1;
    // recursive call xxxx|x
    double smallOutput = gsum(k-1);
    // smaller calculation
    return (smallOutput + 1/pow(2,k));
    
}

int main(void){
    int k;
    std::cin >> k;
    std::cout << gsum(k) << std::endl;
    return 0;
}