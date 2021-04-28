// Problem: https://www.codingninjas.com/codestudio/guided-paths/data-structures-algorithms/content/118820/offering/1381873
#include <iostream>
#include <vector>

using namespace std;

long long maxSubSumKConcat(vector<int> &arr, int n, int k)
{
    // Write your code here
    int currSum = arr[0];
    int overSum = arr[0];

    for (int i = 1; i < n * k; i++)
    {
        int val = arr[i%n];
        if (val + currSum >= val)
            currSum += val;
        else
            currSum = val;

        if (currSum > overSum)
            overSum = currSum;
    }
    return overSum;
}
int main(void)
{
    int n, k;
    cin >> n >> k;
    vector <int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    cout << maxSubSumKConcat(v, n, k) << endl;

    return 0;
}