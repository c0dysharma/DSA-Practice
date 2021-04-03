/*
finds first index of x in array arr of size, size
input:
    size of array
    value to find
    array itself

output:
    place where x comes in array

ex. 
input:
    3
    4
    1 5 4

output:
    3
*/

// way1: recursive call on first part xxxx|x

#include <iostream>

int findAllIndicies(int arr[], int size, int x, int outArr[])
{
    if (size == 0)
        return 0;        

    int smallOutput = findAllIndicies(arr, size - 1, x, outArr);
    if(arr[size-1] == x){
        outArr[smallOutput] = size-1;
        return smallOutput+1;

    }else    
        return smallOutput;
    
}

int main(void)
{
    int size, x;
    std::cin >> size >> x;
    int *arr = new int[size];
    int *outputArr = new int[size];

    for (size_t i = 0; i < size; i++)
    {
        std::cin >> arr[i];
        outputArr[i] = -1;
    }

    std::cout << findAllIndicies(arr, size, x, outputArr) << std::endl;

    delete[] arr;
    return 0;
}