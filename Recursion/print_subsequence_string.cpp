#include <iostream>

void printSubsequence(std::string s, std::string output){
    if(s.empty()){
        std::cout << output << std::endl;
        return;
    }
    
    printSubsequence(s.substr(1), output); // case 1 when we are not taking previous value
    printSubsequence(s.substr(1), output+s[0]); // case 2 when we are taking previous value
} 

int main(void){
    std::string s;
    std::string output = "";
    std::cin >> s; 
    printSubsequence(s,output);  
}