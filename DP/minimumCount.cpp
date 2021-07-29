#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

// bruteforce approach
int minimumCount_bf(int n) {
  // base case
  if (n <= 0)
    return 0;
  if (n == 1)
    return 1;

  // recursive call and smaller calculation
  int i = 1;
  std::vector<int> vals;
  while (std::pow(i, 2) <= n) {
    vals.push_back(minimumCount_bf(n - std::pow(i, 2)));
    i++;
  }

  return *min_element(vals.begin(), vals.end()) + 1;
}
// Memoization
int minimumCount_mem_helper(int *arr, int n) {
  // base case
  if (n <= 0)
    return 0;
  if (n == 1)
    return 1;

  // checking storage if already exists
  if (arr[n] != -1)
    return arr[n];

  // recursive call and smaller calculation
  int i = 1;
  std::vector<int> vals;
  while (std::pow(i, 2) <= n) {
    vals.push_back(minimumCount_mem_helper(arr, n - std::pow(i, 2)));
    i++;
  }
  // storing and returning
  arr[n] = *min_element(vals.begin(), vals.end()) + 1;
  return arr[n];
}

int minimumCount_mem(int n) {
  int arr[n + 1];
  for (int i = 0; i < n + 1; i++) {
    arr[i] = -1;
  }
  return minimumCount_mem_helper(arr, n);
}

// DP
int minimumCount_dp(int n) {
  // getting storage ready
  int arr[n + 1];
  arr[0] = 0;
  arr[1] = 1;

  // fill up the array
  for (int i = 2; i < n + 1; i++) {
    // we gonna need it to find min
    std::vector<int> vals;
    int j = 1;
    while (std::pow(j, 2) <= i) { // add to min list only when j squared is <= i(current val)
      vals.push_back(arr[i - (int)std::pow(j, 2)]);
      j++;
    }
    arr[i] = *min_element(vals.begin(), vals.end()) + 1;
  }
  // the wanted value is on last
  return arr[n];
}

int main(void) {
  int n;
  std::cin >> n;
  // std::cout << minimumCount_bf(n) << std::endl;
  std::cout << minimumCount_mem(n) << std::endl;
  std::cout << minimumCount_dp(n) << std::endl;

  return 0;
}

/*
Coding Problem
Problem Statement: Minimum Count
Problem Level: MEDIUM
Problem Description:
Given an integer N, find and return the count of minimum numbers required to
represent N as a sum of squares. That is, if N is 4, then we can represent it as
: {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. The output will be 1, as 1 is the minimum
count of numbers required to represent N as sum of squares. Input format : The
first and the only line of input contains an integer value, 'N'.

Output format :
Print the minimum count of numbers required.

Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec

Sample Input 1 :
12

Sample Output 1 :
3

Explanation of Sample Output 1 :
12 can be represented as :
A) (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1)
+ (1^1) + (1^1)

B) (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1) + (1^1)  + (2 ^ 2)

C) (1^1) + (1^1) + (1^1) + (1^1) + (2 ^ 2) + (2 ^ 2)

D) (2 ^ 2) + (2 ^ 2) + (2 ^ 2)

As we can see, the output should be 3.

Sample Input 2 :
9

Sample Output 2 :
1
*/