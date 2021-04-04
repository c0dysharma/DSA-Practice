/*
Chapter Assignment
Problem Statement: Replace pi (recursive)
Problem Level: MEDIUM
Problem Description:
Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".

Sample Input 1 :
xpix

Sample Output :
x3.14x

Sample Input 2 :
pipi

Sample Output :
3.143.14

Sample Input 3 :
pip

Sample Output :
3.14p
*/

#include <iostream>

void addPi(char arr[], int len){
    //creating new array with extra size of 3.14 ane \0
    int newLen = 4+len+1;
    char newArr[newLen];
    //adding pi
    newArr[0] = '3';
    newArr[1] = '.';
    newArr[2] = '1';
    newArr[3] = '4';
    //copying remaning part
    for(int i = 4; i<newLen; i++){
        newArr[i] = arr[i-2];
    }
    //copying to original array
    for(int i = 0; i<newLen; i++){
        arr[i] = newArr[i];
    }
}

// void shiftAndAddPi(char arr[], int len){
//     for(int i = len; i >= 0; i--){
//         arr[i+2] = arr[i];
//     }
//     arr[0] = '3';
//     arr[1] = '.';
//     arr[2] = '1';
//     arr[3] = '4';
// }

char* replacePi(char arr[]){
    // getting length of the array
    int len = 0;
    //base case
    while(arr[len] != '\0'){
        len++;
    }
    if(len <= 1)
        return arr;
    // recursive call x|xxxxx
    replacePi(arr+1);
    // small calculation
    if(arr[0]=='p')
        if(arr[1] = 'i'){
             addPi(arr,len);
        }
            
    return arr;
}

int main(void){
    char arr[1000];
    std::cin >> arr;
    std::cout << replacePi(arr) << std::endl;
}