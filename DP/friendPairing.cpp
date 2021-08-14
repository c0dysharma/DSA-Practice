#include <iostream>

int waysToPair_bf(int n) {
  // base case
  if (n == 1 || n == 2) // when only 1 person he can only remain single and 2
    return n;           // have 2 options

  if (n < 1)
    return 0;

  // recursive call and smaller calculation
  return waysToPair_bf(n - 1) +
         (n - 1) *
             waysToPair_bf(n - 2); // or he can pair with any one other person
}

int waysToPair_mem(int n, int *arr) {
  // base case
  if (n == 1 || n == 2) // when only 1 person he can only remain single and 2
    return n;           // have 2 options

  if (n < 1)
    return 0;

  // lookup
  if (arr[n] != -1)
    return arr[n];

  // recursive call and smaller calculation
  return arr[n] =
             waysToPair_bf(n - 1) +
             (n - 1) * waysToPair_bf(
                           n - 2); // or he can pair with any one other person
}

int waysToPair_dp(int n) {
  int dp[n + 1];
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;

  for (int i = 3; i < n + 1; i++) {
    dp[i] = dp[i - 1] + (i - 1) * dp[i - 2];
  }

  return dp[n];
}

int main(void) {
  int n;
  std::cin >> n;
  std::cout << waysToPair_bf(n) << std::endl;

  int arr[n + 1];
  for (int i = 0; i < n + 1; i++) {
    arr[i] = -1;
  }
  std::cout << waysToPair_mem(n, arr) << std::endl;
  std::cout << waysToPair_dp(n) << std::endl;
}

// https://www.youtube.com/watch?v=SHDu0Ufjyk8