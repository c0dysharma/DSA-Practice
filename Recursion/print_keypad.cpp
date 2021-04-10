/*
same as return keypad problem but we have print instead of returning
*/
#include <iostream>

void printKeypad(int num, std::string output){
    //base case
    if(num == 0){
        std::cout << output << std::endl;
        return;
    } 
    //helper value
    std::string vals[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    std::string currentVal = vals[num%10];
    //recursive call and smaller calculation
    for(char ch:currentVal){
        printKeypad(num/10,output+ch);
    }


}

int main(void){
    int num;
    std::string output = "";
    std::cin >> num;
    printKeypad(num, output);
    return 0;
}
