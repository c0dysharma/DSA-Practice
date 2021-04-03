/*
remove consecutive duplicate characters
input:
    sttring 
output:
    same string with duplicates removed
ex
input:
    aabbcdc
output:
    abcdc
*/
#include<iostream>

int getSize(char str[]){
    if(*str == '\0')
        return 0;
    return getSize(str+1) + 1;

}

void removeDuplicate(char str[]){
    int size = getSize(str);
    if(size <= 1){
        return;
    }
    removeDuplicate(str+1);

    if(*str != *(str+1)){
        return;
    }else{
        int i = 1;
        for(; str[i] != '\0'; i++){
            str[i-1] = str[i];
        }
        str[i-1] = str[i];
    }

}

int main(void){
    char str[100];
    std::cin >> str;

    removeDuplicate(str);
    std::cout << str << std::endl;
    return 0;

}