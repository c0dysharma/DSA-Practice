#include <iostream>
// should have used long long instead of int
// too lazy to change now :p

// Approach 1: Recursive Brute Force O(n^2)
int fib_1(int n) {
  // base case
  if (n <= 1)
    return n;

  // recursive call
  int a = fib_1(n - 1);
  int b = fib_1(n - 2);

  // small calculation
  return a + b;
}

// Approach 2: Memoization (Recursive DP) O(n)
int fib_2_helper(int *arr, int n) {
  // base case
  if (n <= 1)
    return n;

  // dp part
  if (arr[n] != -1)
    return arr[n];

  // recursive call and store
  int a = fib_2_helper(arr, n - 1);
  int b = fib_2_helper(arr, n - 2);
  arr[n] = a + b;

  return a + b;
}

// Approach 3: Dyanamic Programming (DP)
int fib_3(int n) {
  int arr[n + 1];
  arr[0] = 0;
  arr[1] = 1;

  for (int i = 2; i < n + 1; i++) {
    arr[i] = arr[i - 1] + arr[i - 2];
  }

  return arr[n];
}

int fib_2(int n) {
  int arr[n + 1];
  for (int i = 0; i < n + 1; i++) {
    arr[i] = -1;
  }
  return fib_2_helper(arr, n);
}

int main(void) {
  int n;
  std::cin >> n;
  std::cout << fib_2(n) << std::endl;
  std::cout << fib_3(n) << std::endl;
  std::cout << fib_1(n) << std::endl;
}