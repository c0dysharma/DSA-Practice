/*
finds last index of x in array arr of size, size
input:
    size of array
    value to find
    array itself

output:
    place where x comes in array

ex. 
input:
    4
    4
    1 4 5 4

output:
    4
*/
#include <iostream>

int findLastIndex(int arr[], int size, int x)
{
    if (size == 0)
        return -1;
    int smallOutput = findLastIndex(arr + 1, size - 1, x);
    if(smallOutput == -1){
        if (*arr == x)
            return 1;
        else
            return -1;
    }return smallOutput+1;
}

int main(void)
{
    int size, x;
    std::cin >> size >> x;
    int *arr = new int[size];

    for (size_t i = 0; i < size; i++)
    {
        std::cin >> arr[i];
    }

    std::cout << findLastIndex(arr, size, x) << std::endl;
    delete[] arr;
    return 0;
}