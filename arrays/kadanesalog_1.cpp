//Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381870
// method 1: which returns non-negative values
#include <iostream>

int kadaneAlgo(int arr[], int n)
{
    int currSum = 0;
    int overSum = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] + currSum >= 0)
            currSum += arr[i];
        else
            currSum = 0;

        if (currSum > overSum)
            overSum = currSum;
    }
    return overSum;
}

int main(void)
{
    int n;
    std::cin >> n;

    int *arr = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
    std::cout << kadaneAlgo(arr, n) << std::endl;
    delete[] arr;
}