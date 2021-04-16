#include <iostream>

void rotateArray(int arr[], int size, int d){
    int remainingElements[d];
    for(int i = 0; i<d; i++){
        remainingElements[i] = arr[i];
    }
    int i = 0;
    for(; i+d<size; i++){
        arr[i] = arr[i+d];
    }
    for(int j = 0; j<d; j++){
        arr[j+i] = remainingElements[j];
    }

}

int main(void){
    int size;
    std::cin >> size;
    int *arr = new int[size];
    for (int i = 0; i < size; i++){
        std::cin >> arr[i];
    }
    int d;
    std::cin >> d;

    rotateArray(arr, size, d);

    for (int i = 0; i < size; i++){
        std::cout << arr[i] << ' ';
    }
    std::cout << std::endl;

    delete[] arr;
    return 0;
}