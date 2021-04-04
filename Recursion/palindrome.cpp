/*
Chapter Assignment
Problem Statement: Check Palindrome (recursive)
Problem Level: MEDIUM
Problem Description:
Check whether a given String S is a palindrome using recursion. Return true or false.
Input Format :
String S

Output Format :
'true' or 'false'

Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.

Sample Input 1 :
racecar

Sample Output 1:
true

Sample Input 2 :
ninja

Sample Output 2:
false
 */
#include <iostream>
#include <string>
#include <iomanip>

bool helper(char S[], int start, int end){
    // base case
    if(start>=end)
        return true;
    //small calculaton and recursive call x|xxxxx|x
    if(S[start]==S[end])
        return helper(S,start+1,end-1);
    else
        return false;
}

bool is_palindrome(char S[]){
    int len = 0;
    while(S[len]!='\0'){
        len++;
    }
    return helper(S,0,len-1);
}

int main(void){
    char S[1000];
    std::cin >> S;
    std::cout << std::boolalpha << is_palindrome(S) << std::endl;
    return 0;
}