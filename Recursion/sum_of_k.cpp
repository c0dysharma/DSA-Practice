// NOT WORKING

/*
Chapter Assignment
Problem Statement: Return subsets sum to K
Problem Level: HARD
Problem Description:
Given an array A of size n and an integer K, return all subsets of A which sum to K.
Subsets are of length varying from 0 to n, that contain elements of the array. But the order of elements should remain same as in the input array.
Note : The order of subsets are not important.
Input format :
Line 1 : Integer n, Size of input array
Line 2 : Array elements separated by space
Line 3 : K

Constraints :
1 <= n <= 20

Sample Input :
9 
5 12 3 17 1 18 15 3 17 
6

Sample Output :
3 3
5 1
*/
#include <iostream>

int sumOfK(int arr[], int n, int k, int** output){
    // base case
    if(n==0){
        if(k==0){
            output[0][0] = 0; 
            return 1;
        }else
            return 0;
    }
    //helper arrays
    int **out1 = new int*[50];
    int **out2 =  new int*[50];
    for(int i = 0; i<50; i++){
        out1[i] = new int[n+1];
        out2[i] = new int[n+1];
    }

    //recusive call
    int smallerOuptut1 = sumOfK(arr+1,n-1,k-arr[0],out1);
    int smallerOutput2 = sumOfK(arr+1,n-1,k,out2);
    //smaller calculation
        // copying out1
    for(int i= 0; i<smallerOuptut1; i++){
        // increment in first val
        output[i][0] = out1[i][0] + 1;
        // adding arr[0] in 2nd place
        output[i][1] = arr[0];
        // copying retunred data
        for(int j = 2; j<out1[i][0]; j++){
            output[i][j] = out1[i][j-1];
        }

    }
        // copying out2
    for (int i = smallerOuptut1; i < smallerOuptut1 + smallerOutput2; i++){
        for(int j = 0; j<out2[i-smallerOuptut1][0]; j++){
            output[i][j] = out2[i][i];
        }
    }

    delete[] out1;
    delete[] out2;
    return smallerOuptut1+smallerOutput2;
}

int main(void){
    int n;
    std::cin >> n;
    int *arr = new int[n];

    for (int i = 0; i < n; i++){
        std::cin >> arr[i];
    }

    int k;
    std::cin >> k;

    int outArrSize = 100;
    int **outArr;
    outArr = new int *[outArrSize];

    for (int i = 0; i < n; i++){
        outArr[i] = new int[n + 1];
    }

    int count = sumOfK(arr, n, k, outArr);

    for (int i = 0; i < count; i++)
    {
        for (int j = 1; j <= outArr[i][0]; j++)
        {
            std::cout << outArr[i][j] << " ";
        }
        std::cout << std::endl;
    }

    delete[] arr;
    delete[] outArr;
    return 0;
}