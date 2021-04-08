/*
Chapter Assignment
Problem Statement: Print Subsets of Array
Problem Level: HARD
Problem Description:
Given an integer array (of length n), find and print all the subsets of input array.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important. Just print the subsets in different lines.
Input format :
Line 1 : Integer n, Size of array
Line 2 : Array elements (separated by space)

Constraints :
1 <= n <= 15

Sample Input:
3
15 20 12

Sample Output:
[] (this just represents an empty array, don't worry about the square brackets)
12 
20 
20 12 
15 
15 12 
15 20 
15 20 12
*/

#include <iostream>
#include <cmath>

int subsets(int arr[], int **outArr, int size){
    // base case
    if(size == 0){
        outArr[0][0] = 0;
        return 1;
    }
    //recursive call
    int smallerOutputSize = subsets(arr+1, outArr, size-1);
    //smaller calculation
    for(int i = 0; i<smallerOutputSize; i++){
        int nextRow = i+smallerOutputSize;
        //copying last item
        outArr[nextRow][1] = arr[0];
        // increment count
        outArr[nextRow][0] = outArr[i][0]+1;
        //copy existing elemnts
        for(int j = 0; j<outArr[i][0]; j++){
            outArr[nextRow][j+2] = outArr[i][j+1];
        }

    }
    return 2*smallerOutputSize;
}

int main(void){
    int arrSize;
    std::cin >> arrSize;

    int* arr = new int[arrSize];
    for(int i=0; i<arrSize; i++){
        std::cin >> arr[i];
    }

    int rowSize = pow(2, arrSize);
    int **outArr;
    outArr = new int*[rowSize];

    for(int i = 0; i<rowSize; i++){
        outArr[i] = new int[arrSize+1];
    }

    subsets(arr, outArr, arrSize);

    for(int i = 0; i<rowSize; i++){
        for (int j = 1; j <= outArr[i][0]; j++){
            std::cout << outArr[i][j] << " ";
        }std::cout << std::endl;
    }
    delete[] arr;
    delete[] outArr;
    return 0;
}