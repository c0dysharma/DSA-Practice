#include <iostream>

void swap(int& a, int &b){
    int temp = b;
    b = a;
    a = temp;
}

void selectionSort(int arr[], int size){
    //smaller calculation
    if(size == 1)
        return;

    //smaller calculation
    int minIndex = 0;
    for(int i = 0; i<size; i++){
        if(arr[i] < arr[minIndex])
            minIndex = i;
    }
    swap(arr[minIndex],arr[0]);
    //recursive call
    selectionSort(arr+1,size-1);

}

int main(void){
    int size;
    std::cin >> size;

    int* arr = new int[size];
    for(int i = 0; i<size; i++){
        std::cin >> arr[i];
    }

    selectionSort(arr, size);
    
    for (int i = 0; i < size; i++){
        std::cout << arr[i] << ' ';
    }std::cout << std::endl;
}