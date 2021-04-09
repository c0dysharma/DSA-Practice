/*
Coding Problem
Problem Statement: Return Keypad - String
Problem Level: HARD
Problem Description:
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
Input Format :
Integer n

Output Format :
All possible strings in different lines

Constraints :
1 <= n <= 10^6

Sample Input:
23

Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/
#include <iostream>

int returnKeypad(int num, std::string output[]){
    //helper value
    std::string vals[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    //base case
    if(num == 0 || num == 1){
        output[0] = vals[num];
        return 1;
    }
    //recursive call
    int smallerOutput = returnKeypad(num/10,output);
    //smaller calculation
    std::string currentVal = vals[num%10];
    int count = currentVal.size();
    
    //calculation in temp array
    std::string temp[count*smallerOutput];
    int k=0;
    for(int i = 0; i<smallerOutput; i++){
        for(int j = 0; j<count; j++){
            temp[k] = currentVal[j]+output[i];
            k++;
        }
    }

    //copying back to original array
    for(int i =0;  i<k; i++){
        output[i] = temp[i];
    }

    return count*smallerOutput;

}

int main(void){
    int num;
    std::cin >>  num;
    std::string output[100];

    int count = returnKeypad(num, output);
    for(int i=0; i<count; i++){
        std::cout << output[i] << std::endl;
    }
    return 0;
}
