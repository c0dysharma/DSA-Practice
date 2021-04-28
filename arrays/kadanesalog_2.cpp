//Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381870
// method 2: which returns negative values
#include <iostream>

int kadaneAlgo(int arr[], int n)
{
    int currSum = arr[0];
    int overSum = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (arr[i] + currSum >= arr[i])
            currSum += arr[i];
        else
            currSum = arr[i];

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