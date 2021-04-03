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
#include <iostream>

int findFirstIndex(int arr[], int size, int x)
{
    if (size == 0)
        return -1;

    if (*arr == x)
        return 1;

    int smallOutput = findFirstIndex(arr + 1, size - 1, x);
    return (smallOutput == -1) ? -1 : smallOutput + 1;
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

    std::cout << findFirstIndex(arr, size, x) << std::endl;
    delete[] arr;
    return 0;
}