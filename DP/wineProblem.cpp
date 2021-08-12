#include <iostream>
int dp[100][100];
// brute force approach
int wineProblem_bf(int *arr, int size, int year = 1) {
  // base case
  if (size == 1) {
    return arr[0] * year;
  }

  // recursive call
  int sum1 =
      (arr[0] * year) +
      wineProblem_bf(arr + 1, size - 1, year + 1); // when we take 1st element
  int sum2 = wineProblem_bf(arr, size - 1, year + 1) +
             (arr[size - 1] * year); // when we take last element

  // smaller calculation
  return std::max(sum1, sum2);
}

// memoization
int wineProblem_mem(int *arr, int startIndex, int endIndex, int year = 1) {
  // base case
  if (startIndex > endIndex)
    return 0;

  if (startIndex == endIndex)
    return arr[startIndex] * year;

  // check dp
  if (dp[startIndex][endIndex] != 0)
    return dp[startIndex][endIndex];

  // recursive call
  int sum1 = (arr[startIndex] * year) +
             wineProblem_mem(arr, startIndex + 1, endIndex, year + 1);

  int sum2 = wineProblem_mem(arr, startIndex, endIndex - 1, year + 1) +
             (arr[endIndex] * year);

  // smaller calculation
  return dp[startIndex][endIndex] = std::max(sum1, sum2);
}

// dp approach
int wineProblem_dp(int *arr, int size) {
  int dp[size][size] = {0};

  int startIndex = 0;
  int endIndex = 0;

  //(flow of the loop is shown int the last)
  // run through the loop till we reach end
  for (; startIndex != size && endIndex != size; startIndex++, endIndex++) {
    // when i==j
    dp[startIndex][endIndex] =
        arr[startIndex] * size; // beacause we are on last year

    // saving startIndex value to get back it later
    int temp = startIndex;
    startIndex--; // decreasing the value to go up in the matrix
    // keep going up till we reach first row
    while (startIndex >= 0) {
      // fill the current cell
      int year = size - (endIndex - startIndex);
      int sum1 = arr[startIndex] * year + dp[startIndex + 1][endIndex];
      int sum2 = arr[endIndex] * year + dp[startIndex][endIndex - 1];
      dp[startIndex][endIndex] = std::max(sum1, sum2);
      // go up
      startIndex--;
    }
    // revert from where we started
    startIndex = temp;
  }

  // rest options are when i>j which will remain 0
  return dp[0][size - 1];
}

int main(void) {
  int size;
  std::cin >> size;
  int arr[size];
  for (int i = 0; i < size; i++) {
    std::cin >> arr[i];
  }

  std::cout << wineProblem_bf(arr, size) << std::endl;
  // size-1 because index starts to 0 :p
  std::cout << wineProblem_mem(arr, 0, size - 1) << std::endl;
  std::cout << wineProblem_dp(arr, size) << std::endl;

  return 0;
}

// https://www.geeksforgeeks.org/maximum-profit-sale-wines/
// loop flow
/*
say we have [2,3,5]
matrix look like this
[0 0 0]
[0 0 0]
[0 0 0]

at first iteration
[6 0 0]
[0 0 0]
[0 0 0]

at next iteration
value of cell - will be filled
[6 - 0] -> [6 13 0]
[0 9 0] -> [0 9 0]
[0 0 0] -> [0 0 0]

next iteration
value of cell - will be filled
[6 13 0] -> [6 13 0]
[0 9 -]  -> [6 9 21]
[0 0 15] -> [0 0 15]

[6 13 -] -> [6 13 23]
[6 9 21] -> [6 9 21]
[0 0 15] -> [0 0 15]

now after returning from last iteration and incrementig value we reached on
startIndex=endIndex=3

which is beyond range so we exited
our value is alreay on (0,2)
*/