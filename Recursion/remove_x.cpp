/*
Chapter Assignment
Problem Statement: Remove X
Problem Level: MEDIUM
Problem Description:
Given a string, compute recursively a new string where all 'x' chars have been removed.
Input format :
String S

Output format :
Modified String

Constraints :
1 <= |S| <= 10^3
where |S| represents the length of string S.

Sample Input 1 :
xaxb

Sample Output 1:
ab

Sample Input 2 :
abc

Sample Output 2:
abc

Sample Input 3 :
xx

Sample Output 3:

*/
#include <iostream>

void removeX(char S[])
{
    //base case
    if (*S == '\0')
        return;
    //recursive call x|xxxx
    removeX(S + 1);
    //smaller calculation
    if (*S == 'x')
    {
        // getting size of string
        int len = 0;
        while (S[len] != '\0')
            len++;
        len++; //one space extra for null character

        //shift everythin to left
        for (int i = 0; i < len; i++)
        {
            S[i] = S[i + 1];
        }
    }
}

int main(void)
{
    char S[1000];
    std::cin >> S;
    removeX(S);
    std::cout << S << std::endl;
    return 0;
}