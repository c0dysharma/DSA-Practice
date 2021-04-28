//Problem https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381872

#include <iostream>

int flipBits(int *arr, int n)
{
    // WRITE YOUR CODE HERE
    int csum = (arr[0] == 1) ? -1 : 1;
    int osum = (arr[0] == 1) ? -1 : 1;
    int numberOf1s = arr[0];

    for (int i = 1; i < n; i++)
    {
        int val = 0;
        if (arr[i] == 1)
        {
            val = -1;
            numberOf1s++;
        }
        else
            val = 1;

        if (val + csum >= val)
            csum += val;
        else
            csum = val;

        if (csum > osum)
            osum = csum;
    }
    if (osum > 0)
        return numberOf1s + osum;
    return numberOf1s;
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
    std::cout << flipBits(arr, n) << std::endl;
    delete[] arr;
}