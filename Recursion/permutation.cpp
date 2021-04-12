/*
Chapter Assignment
Problem Statement: Return Permutations - String
Problem Level: HARD
Problem Description:
Given a string S, find and return all the possible permutations of the input string.
Note 1 : The order of permutations is not important.
Note 2 : If original string contains duplicate characters, permutations will also be duplicates.
Input Format :
String S

Output Format :
All permutations (in different lines)

Sample Input :
abc

Sample Output :
abc
acb
bac
bca
cab
cba
*/

#include <bits/stdc++.h>

void getPermutation(std::string s, std::string output, std::vector<std::string> &vec){
    // base case
    if(s.empty()){
        vec.push_back(output);
        return;
    }
    // smaller calculation
    for(int i = 0; i<s.size(); i++){
        std::string str = s;
        getPermutation(str.erase(i,1),output+s.at(i),vec);
    }
}

    int main(void)
{
    std::string s, output;
    std::vector <std::string> vec;
    std::cin >> s;
    
    getPermutation(s,output,vec);

    for(auto a:vec){
        std::cout << a << std::endl;
    }
    return 0;
}