#include <iostream>
// iterative approach
void insertionSort(int arr[], int size){
    for(int j = 1; j<size; j++){
        int i = j-1;
        int key = arr[j];
        while(i>= 0 && arr[i] > key){
            arr[i+1] = arr[i];
            i--;
        }
        arr[++i] = key;
    }
}

int main(void){
    int size;
    std::cin >> size;
    int *arr = new int[size];

    for(int i=0; i<size; i++){
        std::cin >> arr[i];
    }

    insertionSort(arr,size);

    for (int i = 0; i < size; i++){
        std::cout << arr[i] << ' ';
    }std::cout << std::endl;

    delete[] arr;
}