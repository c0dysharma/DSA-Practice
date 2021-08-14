#include <iostream>

// brute force approach
int catlan_bf(int num) {
  // base case
  if (num == 0 || num == 1)
    return 1;

  // smaller calc and recursive callcd
  int ans = 0;
  for (int i = 0; i < num; i++) {
    ans += catlan_bf(i) * catlan_bf(num - i - 1);
  }
  return ans;
}

// memoized
int catlan_mem(int num, int *arr) {
  // base case
  if (num == 0 || num == 1)
    return 1;

  // check
  if (arr[num] != 0)
    return arr[num];

  // smaller calc and recursive callcd
  int ans = 0;
  for (int i = 0; i < num; i++) {
    ans += catlan_mem(i, arr) * catlan_mem(num - i - 1, arr);
  }

  return arr[num] = ans;
}

// dp bottom up
int catlan_dp(int num) {

  int arr[num + 1];
  arr[0] = 1;
  arr[1] = 1;

  for (int i = 2; i < num + 1; i++) {
    arr[i] = 0;
    for (int j = 0; j < i; j++) {
      arr[i] += arr[j] * arr[i - j - 1];
    }
  }

  return arr[num];
}

int main(void) {
  int num;
  std::cin >> num;

  std::cout << catlan_bf(num) << std::endl;
  int arr[num + 1] = {0};
  std::cout << catlan_mem(num, arr) << std::endl;
  std::cout << catlan_dp(num) << std::endl;

  return 0;
}