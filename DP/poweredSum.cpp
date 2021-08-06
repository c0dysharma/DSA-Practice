#include <cmath>
#include <iostream>

// recursive solution
int poweredSum_bf(int a, int b, int num = 1) {
  // base case
  int val = a - std::pow(num, b);
  if (val == 0)
    return 1;
  if (val < 0)
    return 0;

  // recursive call
  return poweredSum_bf(val, b, num + 1)  // we can either take the number
         + poweredSum_bf(a, b, num + 1); // or we don't
}

// dp solution

int poweredSum_dp(int a, int b) {
  std::pair<int, bool> arr[a + 1];
  arr[0].first = 0;
  arr[1].first = 1;

  for (int i = 2; i < a + 1; i++) {
    int val = 0;
    for (int j = 1; std::pow(j, b) <= i; j++) {
      int remainingVal = i - std::pow(j, 2);
      if (arr[remainingVal].first >= 1) {
        int previousVal = i - remainingVal;
        arr[previousVal].second = true;
        // means previous value isn't used already
        if (!arr[remainingVal].second)
          val++;
      } else if (remainingVal == 0)
        val++;
      continue;
    }
    arr[i].first = val;
  }

  return arr[a].first;
}

int main(void) {
  int a, b;
  std::cin >> a >> b;

  std::cout << poweredSum_bf(a, b) << std::endl;
  std::cout << poweredSum_dp(a, b) << std::endl;
}

/*
Chapter Assignment
Problem Statement: All possible ways
Problem Level: MEDIUM
Problem Description:
Given two integers a and b. You need to find and return the count of possible
ways in which we can represent the number a as the sum of unique integers raise
to the power b. For eg. if a = 10 and b = 2, only way to represent 10 as - 10 =
1^2 + 3^2

Hence, answer is 1.
Note : x^y represents x raise to the power y
Inout Format :
Two integers a and b (separated by space)

Output Format :
Count

Constraints :
1 <= a <= 10^5
1 <= b <= 50

Sample Input 1 :
10 2

Sample Output 1 :
1

Sample Input 2 :
100 2

Sample Output 2 :
3
*/