#include <algorithm>
#include <climits>
#include <iostream>
#include <vector>

// using arrays instead of vectors this time

// bruteforce approach
int minimumCoinChange_bf(int n, int coins[], int size) {
  // base case
  if (n == 0)
    return 0;

  // recursive calls
  int temp[size] = {0};
  for (int i = 0; i < size; i++) {
    int val = n - coins[i];
    if (val >= 0)
      temp[i] = minimumCoinChange_bf(val, coins, size);
  }

  // smaller calculation
  return *std::min_element(temp, temp + size) + 1;
}

// memoized approach
int minimumCoinChange_mem(int n, int coins[], int size, int arr[]) {
  // base case
  if (n == 0)
    return 0;

  // lookup
  if (arr[n] != 0)
    return arr[n];

  // recursive calls
  int temp[size] = {0};

  for (int i = 0; i < size; i++) {
    int val = n - coins[i];
    if (val >= 0)
      temp[i] = minimumCoinChange_mem(val, coins, size, arr);
  }

  // smaller calculation
  arr[n] = *std::min_element(temp, temp + size) + 1;
  return arr[n];
}

// bottom up approach
int minimumCoinChange_dp(int n, int coins[], int size) {
  int arr[n + 1];
  arr[0] = 0;

  for (int i = 1; i < n+1; i++) {
    std::vector<int> temp;
    for (int j = 0; j < size; j++) {
      int val = i - coins[j];
      if(val==0)
        temp.push_back(arr[0]);

      if (val > 0 && arr[val] > 0)
        temp.push_back(arr[val]);
    }
    if (temp.size() != 0)
      arr[i] = *std::min_element(temp.begin(), temp.end()) + 1;
    else
      arr[i] = 0;
  }
  return arr[n];
}

int main(void) {
  int n, size;
  std::cin >> n >> size;
  int coins[size];

  for (int i = 0; i < size; i++) {
    std::cin >> coins[i];
  }
  int arr[n + 1] = {0};
  std::cout << minimumCoinChange_mem(n, coins, size, arr) << std::endl;
  // std::cout << minCoins(coins, size, n) << std::endl;
  std::cout << minimumCoinChange_dp(n, coins, size) << std::endl;
  std::cout << minimumCoinChange_bf(n, coins, size) << std::endl;


  return 0;
}

// https://www.geeksforgeeks.org/find-minimum-number-of-coins-that-make-a-change/