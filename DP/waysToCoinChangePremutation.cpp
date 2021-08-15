#include <iostream>

int waysToChange_bf(int n, int *coins, int m) {
  // base case
  if (n == 0)
    return 1;

  // recursive call
  int ans = 0;
  for (int i = 0; i < m; i++) {
    int val = n - coins[i];
    if (val >= 0)
      ans += waysToChange_bf(val, coins, m);
  }

  return ans;
}

int waysToChange_mem(int n, int *coins, int m, int *arr) {
  // base case
  if (n == 0)
    return 1;

  // lookup
  if (arr[n] != 0)
    return arr[n];

  // recursive call
  int ans = 0;
  for (int i = 0; i < m; i++) {
    int val = n - coins[i];
    if (val >= 0)
      ans += waysToChange_mem(val, coins, m, arr);
  }

  return arr[n] = ans;
}

int waysToChange_dp(int n, int* coins, int m){
    int dp[n+1];
    dp[0] = 1;

    // for every i
    for(int i = 1 ; i<n+1; i++){
        int ans = 0;
        // for every coin
        for(int j = 0; j<m; j++){
            int val = i-coins[j];
            if(val >= 0)
                ans+= dp[val];
        }
        dp[i] = ans;
    }

    return dp[n];
}

int main(void) {
  int n, m;
  std::cin >> n >> m;

  int coins[n];
  for (int i = 0; i < m; i++) {
    std::cin >> coins[i];
  }
  std::cout << waysToChange_bf(n, coins, m) << std::endl;
  int arr[n + 1] = {0};
  std::cout << waysToChange_mem(n, coins, m, arr) << std::endl;
  std::cout << waysToChange_dp(n, coins, m) << std::endl;
}

// coin change permutation problem
// https: // www.youtube.com/watch?v=yc0LunmJA1A