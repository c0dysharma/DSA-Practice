/*
Chapter Assignment
Problem Statement: Return all codes - String
Problem Level: HARD
Problem Description:
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. Write a program to return the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. And input string does not contain 0s.
Input format :
A numeric string

Constraints :
1 <= Length of String S <= 10

Sample Input:
1123

Sample Output:
aabc
kbc
alc
aaw
kw
*/
#include <iostream>
#include <vector>

void returnAllCodes(std::string s,std::string output, std::vector <std::string> &vec){
    //base case
    if(s.empty()){
        vec.push_back(output);
        return;
    }

    // smaller calculation
    int firstValInt = s.at(0) - '0';
    char firstValChar = 'a' + firstValInt - 1;
    int initalTwoDigits = std::stoi(s.substr(0, 2));
    char initialTwoChars = 'a' + initalTwoDigits - 1;

    // recursive call
    returnAllCodes(s.substr(1),output+firstValChar,vec);
    if (initalTwoDigits >= 10 && initalTwoDigits <= 26)
        returnAllCodes(s.substr(2), output+initialTwoChars, vec);

}

int main(void){
    std::string s, output;
    std::cin >> s;
    std::vector <std::string> vec;

    returnAllCodes(s,output,vec);
    for(auto string:vec){
        std::cout << string << std::endl;
    }
    return 0;
}