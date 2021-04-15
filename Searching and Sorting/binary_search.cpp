#include <iostream>

int binarySearch(int arr[],int start, int end, int x){
    //base case
    if(start>end)
        return -1;
    //smaller calculation and recursive call
    int mid = (start+end)/2;
    
    if(arr[mid] == x)
        return mid;
    else if(x > arr[mid])
        return binarySearch(arr,mid+1,end,x);
    else
        return binarySearch(arr,0,mid-1,x);
} 

int main(void){
    int size;
    std::cin >> size;
    int* arr = new int[size];
    for(int i = 0; i<size; i++){
        std::cin >> arr[i];
    }
    int x;
    std::cin >> x;
    std::cout << binarySearch(arr,0,size,x) << std::endl;
    delete[] arr;
    return 0;
}