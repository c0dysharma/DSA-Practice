#include <iostream>

int waysToChange(int n, int m, int *coins) {
  int dp[n + 1] = {0};
  dp[0] = 1; // we have 1 way to pay nothing; just to make logic work

  for (int i = 0; i < m; i++) {       // for every coin i
    for (int j = 1; j < n + 1; j++) { // and for every number j
      int val = j - coins[i];
      if (val >= 0)
        dp[j] += dp[val];
    }
  }
  return dp[n];
}

int main(void) {
  int n, m;
  std::cin >> n >> m;
  int coins[m];
  for (int i = 0; i < m; i++) {
    std::cin >> coins[i];
  }

  std::cout << waysToChange(n, m, coins) << std::endl;
}

// https://www.youtube.com/watch?v=l_nR5X9VmaI