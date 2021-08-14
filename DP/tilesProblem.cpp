#include <iostream>

// bruteforce
int waysToTile_bf(int n, int m) {
  // base case
  if (n == 1 || n == 0)
    return 1;

  if (n < 0)
    return 0;

  // recursive call and smaller calculation
  return waysToTile_bf(n - 1, m) + waysToTile_bf(n - m, m);
}
// memoized
int waysToTile_mem(int n, int m, int *arr) {
  // base case
  if (n == 1 || n == 0)
    return 1;

  if (n < 0)
    return 0;

  // check if exits
  if (arr[n] != -1)
    return arr[n];

  // recursive call and smaller calculation
  return arr[n] = waysToTile_bf(n - 1, m) + waysToTile_bf(n - m, m);
}

// dp bottom up
int waysToTile_dp(int n, int m) {
  int arr[n + 1];
  arr[0] = 1;
  arr[1] = 1;

  for (int i = 2; i < n + 1; i++) {
    int num1 = arr[i - 1];
    int num2 = (i - m >= 0) ? arr[i - m] : 0;
    arr[i] = num1 + num2;
  }

  return arr[n];
}

int main(void) {
  int n, m;
  std::cin >> n >> m;
  std::cout << waysToTile_bf(n, m) << std::endl;
  int arr[n + 1];
  for (int i = 0; i < n + 1; i++) {
    arr[i] = -1;
  }
  std::cout << waysToTile_mem(n, m, arr) << std::endl;
  std::cout << waysToTile_dp(n, m) << std::endl;

  return 0;
}