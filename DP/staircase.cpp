#include <iostream>

// Memoization (Top to bottom approach)
int staircase_mem_helper(int *arr, int n) {
  // base case
  if (n == 0) // since going from ground to 1st can have only 1 way
    return 1;
  if (n < 0) // no way we can't go underground
    return 0;

  // small calculation and recursive call
  // check if it's already in
  if (arr[n] != -1)
    return arr[n];

  // no its not
  int a = staircase_mem_helper(arr, n - 1); // 1 step
  int b = staircase_mem_helper(arr, n - 2); // 2 steps
  int c = staircase_mem_helper(arr, n - 3); // 3 steps

  // store the shit
  arr[n] = a + b + c;
  return arr[n];
}

int staircase_mem(int n) {
  int arr[n + 1];
  for (int i = 0; i < n + 1; i++) {
    arr[i] = -1;
  }
  return staircase_mem_helper(arr, n);
}

// DP way (Bottom to Top)
int staircase_dp(int n) {
  // creating storage and filling base values
  int arr[n + 2];
  arr[0] = 1; // same ground to 1 takes 1 step
  arr[1] = 1; // and 1 to 2 takes on step
  arr[2] = 2; // 1+1 = 2

  for (int i = 3; i < n + 1; i++) {
    // for 1, 2 and 3 steps
    arr[i] = arr[i - 1] + arr[i - 2] + arr[i - 3];
  }
  return arr[n];
}

int main(void) {
  int n;
  std::cin >> n;

  std::cout << staircase_mem(n) << std::endl;
  std::cout << staircase_dp(n) << std::endl;
}

/*
Coding Problem
Problem Statement: Staircase
Problem Level: MEDIUM
Problem Description:
A child runs up a staircase with 'n' steps and can hop either 1 step, 2 steps or
3 steps at a time. Implement a method to count and return all possible ways in
which the child can run-up to the stairs. Input format : The first and the only
line of input contains an integer value, 'n', denoting the total number of
steps.

Output format :
Print the total possible number of ways.

Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec

Sample Input 1:
4

Sample Output 1:
7

Sample Input 2:
10

Sample Output 2:
274
*/