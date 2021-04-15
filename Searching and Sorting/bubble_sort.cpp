#include <iostream>

void swap(int &a, int &b){
    int temp = b;
    b = a;
    a = temp;
}

void bubbleSort(int arr[], int size){
    //base case
    if (size == 1)
        return;

    //smaller caclulation
    for(int i = 0; i<size-1; i++){
        if(arr[i] > arr[i+1])
            swap(arr[i], arr[i+1]);
    }
    //recursive call
    bubbleSort(arr,size-1);
}

int main(void){
    int size;
    std::cin >> size;

    int *arr = new int[size];
    for (int i = 0; i < size; i++){
        std::cin >> arr[i];
    }

    bubbleSort(arr, size);

    for (int i = 0; i < size; i++){
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;
}