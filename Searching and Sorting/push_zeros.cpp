
#include <iostream>

void swap(int& a , int& b){
    int temp = b;
    b = a;
    a = temp;
}

void pushZeros(int arr[], int size){
    int count = 0;
    for(int i = 0; i<size; i++){
        if(arr[i] != 0)
            swap(arr[count++], arr[i]);
    }
}

int main(void){
    int size;
    std::cin >> size;
    int* arr = new int[size];
    for(int i = 0; i<size; i++){
        std::cin >> arr[i];
    }

    pushZeros(arr, size);

    for (int i = 0; i < size; i++){
        std::cout << arr[i] << ' ';
    }std::cout << std::endl;

    delete[] arr;
    return 0;

}