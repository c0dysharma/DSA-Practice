#include <iostream>1

int lsi(int *input, int n) {
  int arr[n];
  arr[0] = 1;

  for (int i = 1; i < n; i++) {
    arr[i] = 1;
    for (int j = i - 1; j >= 0; j--) {
      if (input[j] >= input[i])
        continue;
      arr[i] = (arr[j] + 1 > arr[i]) ? arr[j] + 1 : arr[i];
    }
  }

  int best = arr[0];
  for (int i = 1; i < n; i++) {
    best = (arr[i] > best) ? arr[i] : best;
  }

  return best;
}

int main(void) {
  int n;
  std::cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) {
    std::cin >> arr[i];
  }
  std::cout << lsi(arr, n) << std::endl;
}

/*
Chapter Assignment
Problem Statement: Longest Increasing Subsequence
Problem Level: MEDIUM
Problem Description:
Given an array with N elements, you need to find the length of the longest
subsequence of a given sequence such that all elements of the subsequence are
sorted in strictly increasing order. Input Format Line 1 : An integer N Line 2 :
Elements of arrays separated by spaces

Output Format
Line 1 : Length of longest subsequence

Input Constraints
1 <= n <= 10^3

Sample Input :
6
5 4 11 1 16 8

Sample Output 1 :
3

Sample Output Explanation
Length of longest subsequence is 3 i.e. (5,11,16) or (4,11,16).

Sample Input 2:
3
1 2 2

Sample Output 2 :
2

*/