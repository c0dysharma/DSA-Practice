/*
Chapter Assignment
Problem Statement: Binary Search (Recursive)
Problem Level: EASY
Problem Description:
Given an integer sorted array (sorted in increasing order) and an element x, find the x in given array using binary search. Return the index of x.
Return -1 if x is not present in the given array.
Note : If given array size is even, take first mid.
Input format :
Line 1 : Array size
Line 2 : Array elements (separated by space)
Line 3 : x (element to be searched)

Sample Input :
6
2 3 4 5 6 8 
5

Sample Output:
3
*/
#include <iostream>

int binarySearch(int arr[], int size, int x){
    //base case
    if(size == 0){
        if (arr[size] == x)
            return size;
        return -1;
    }
        

    // mid point
    int mid = 0;
    if(size%2 == 0)
        mid = (size/2) - 1;
    else
        mid = (size/2);

    //recursive call with smaller calculation
    if(arr[mid] == x)
        return mid;
    else if(arr[mid] > x)
        return binarySearch(arr,mid+1, x);
    else
        return binarySearch(arr+mid,size-mid, x) + mid;
    

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

    std::cout << binarySearch(arr,size,x) << std::endl;

    delete[] arr;

    return 0;
}