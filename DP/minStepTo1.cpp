#include <climits>
#include <iostream>

// Brute force approach- Recursive
int minStepTo1_bf(int n) {
  // base case
  if (n == 1)
    return 0;

  int x = minStepTo1_bf(n - 1);

  int y = INT_MAX;
  if (n % 2 == 0)
    y = minStepTo1_bf(n / 2);

  int z = INT_MAX;
  if (n % 3 == 0)
    z = minStepTo1_bf(n / 3);

  return std::min(x, std::min(y, z)) + 1;
}

// Memoization
int minStepTo1_mem_helper(int *arr, int n) {
  // base case
  if (n == 1)
    return 0;

  // small calculation and recursive call
  if (arr[n] != -1)
    return arr[n];

  int x = minStepTo1_mem_helper(arr, n - 1);

  int y = INT_MAX;
  if (n % 2 == 0)
    y = minStepTo1_mem_helper(arr, n / 2);

  int z = INT_MAX;
  if (n % 3 == 0)
    z = minStepTo1_mem_helper(arr, n / 3);

  // storing value
  arr[n] = std::min(x, std::min(y, z)) + 1;
  return arr[n];
}
int minStepTo1_mem(int n) {
  int arr[n + 1];
  for (int i = 0; i < n + 1; i++) {
    arr[i] = -1;
  }
  return minStepTo1_mem_helper(arr, n);
}

// DP
int minStepTo1_dp(int n) {
  // storage
  int arr[n + 1];
  arr[0] = 0;
  arr[1] = 0;

  // filling up and acessing filled
  for (int i = 2; i < n + 1; i++) {
    int x = arr[i - 1];

    int y = INT_MAX;
    if (i % 2 == 0)
      y = arr[i / 2];

    int z = INT_MAX;
    if (i % 3 == 0)
      z = arr[i / 3];

    arr[i] = std::min(x, std::min(y, z)) + 1;
  }
  // once done time to return
  return arr[n];
}

int main(void) {
  int n;
  std::cin >> n;
  std::cout << minStepTo1_bf(n) << std::endl;
  std::cout << minStepTo1_mem(n) << std::endl;
  std::cout << minStepTo1_dp(n) << std::endl;

  return 0;
}

/*

Coding Problem
Problem Statement: Min Steps to one using DP
Problem Level: EASY
Problem Description:
Given a positive integer 'n',  find and return the minimum number of steps that
'n' has to take to get reduced to 1. You can perform any one of the following 3
steps: 1.) Subtract 1 from it. (n = n - ­1) , 2.) If n is divisible by 2, divide
by 2.( if n % 2 == 0, then n = n / 2 ) , 3.) If n is divisible by 3, divide
by 3. (if n % 3 == 0, then n = n / 3 ).

Input format :
The first and the only line of input contains an integer value, 'n'.

Output format :
Print the minimum number of steps.

Constraints :
1 <= n <= 10 ^ 6

Time Limit: 1 sec

Sample Input  1 :
4

Sample Output  1 :
2

Explanation of Sample Output 1 :
For n = 4
Step 1 :  n = 4 / 2  = 2
Step 2 : n = 2 / 2  =  1

Sample Input  2 :
7

Sample Output  2 :
3

Explanation of Sample Output 2 :
For n = 7
Step 1 :  n = 7 ­- 1 = 6
Step 2 : n = 6  / 3 = 2
Step 3 : n = 2 / 2 = 1

*/