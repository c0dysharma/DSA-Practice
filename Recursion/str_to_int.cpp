/*
Chapter Assignment
Problem Statement: String to Integer
Problem Level: MEDIUM
Problem Description:
Write a recursive function to convert a given string into the number it represents. That is input will be a numeric string that contains only numbers, you need to convert the string into corresponding integer and return the answer.
Input format :
Numeric string S (string, Eg. "1234")

Output format :
Corresponding integer N (int, Eg. 1234)

Constraints :
1 <= |S| <= 9
where |S| represents length of string S.

Sample Input 1 :
1231

Sample Output 1 :
1231

Sample Input 2 :
12567

Sample Output 2 :
12567
*/
#include <iostream>
#include <cmath>

int strToInt(char S[]){
    //getting len for basecase and join first and remaining values
    int len = 0;
    while (S[len] != '\0'){
        len++;
    }
    //base case
    if(len == 1)
        return S[0]-48;
    //recursice call
    int smallerOutput = strToInt(S+1);
    //smaller calculation  | storing char value into int return ASCII of that char reducing 48 gives exact value
    // for ex ASCII value of 1 is 49
    int x = *S - 48;
    //ex- '123' we get '23' as sO and 1 as x. so 1*10^2 = 100, 100+23= 123
    return (x*pow(10,len-1) + smallerOutput);
}

int main(void){
    char S[10];
    std::cin >> S;
    std::cout << strToInt(S) << std::endl;
}