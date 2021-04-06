/*
Chapter Assignment
Problem Statement: Staircase
Problem Level: EASY
Problem Description:
A child is running up a staircase with N steps, and can hop either 1 step, 2 steps or 3 steps at a time. Implement a method to count how many possible ways the child can run up to the stairs. You need to return number of possible ways W.
Input format :
Integer N

Output Format :
Integer W

Constraints :
1 <= N <= 30

Sample Input 1 :
4

Sample Output 1 :
7

Sample Input 2 :
5

Sample Output 2 :
13
*/

#include <iostream>

int waysToRun(int N){
    // base case
    if(N==1 || N==0)
        return 1;
    if(N<0)
        return 0;
    // recursive call and return| we have three ways 1 step at a time, 2 steps or 3 steps
    return (waysToRun(N-1) + waysToRun(N-2) + waysToRun(N-3));

    
}

int main(void){
    int N;
    std::cin >> N;
    std::cout << waysToRun(N) << std::endl;
    return 0;
}
