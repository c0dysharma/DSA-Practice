/*
Chapter Assignment
Problem Statement: Pair star
Problem Level: MEDIUM
Problem Description:
Given a string S, compute recursively a new string where identical chars that are adjacent in the original string are separated from each other by a "*".
Input format :
String S

Output format :
Modified string

Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.

Sample Input 1 :
hello

Sample Output 1:
hel*lo

Sample Input 2 :
aaaa

Sample Output 2 :
a*a*a*a
*/
#include <iostream>

void pairStars(char S[]){
    //base case
    if (*S == '\0')
        return;

    //recursive call x|xxxx
    pairStars(S + 1);
    //smaller calculation
    if(S[0] == S[1]){
        // getting size
        int len = 0;
        while (S[len]!='\0'){
            len++;
        }len++; // one extra len for null character 
        // shifting arr+1 to right by 1 and addinng *
        for(int i=len; i>=2; i--){
            S[i] = S[i-1];
        }S[1] = '*';
        
    }
}

int main(void)
{
    char S[1000];
    std::cin >> S;
    pairStars(S);
    std::cout << S << std::endl;
    return 0;
}