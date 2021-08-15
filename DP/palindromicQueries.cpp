#include <algorithm>
#include <iostream>

// bruteforce way
bool checkPalindrome_bf(std::string str, int l, int r) {
  // base case
  if (l == r) // str of length 1 is a palindrome
    return true;

  if ((r - l) == 1 &&
      str.at(l) == str.at(r)) // when we have only 2 len if they are equal
    return true;              // they are palindrome

  // recursive call
  return str.at(l) == str.at(r) && checkPalindrome_bf(str, l + 1, r - 1);
}

// Memoized approach
// helper print function
void print(int k) {
  if (k == 1)
    std::cout << "true" << std::endl;
  else if (k == 2)
    std::cout << "false" << std::endl;
  else
    std::cout << "Something is wrong" << std::endl;
}

int arr[100][100] = {0}; // assuming size of string <100
int checkPalindrome_mem(std::string str, int l, int r) {

  // base case
  if (l == r) // str of length 1 is a palindrome
    return true;

  if ((r - l) == 1 &&
      str.at(l) == str.at(r)) // when we have only 2 len if they are equal
    return true;              // they are palindrome

  // I will be using 1 for true and 2 for false and 0 for not defined
  // lookup
  if (arr[l][r] != 0)
    return arr[l][r];

  // else find and store with recursive call
  int ans = str.at(l) == str.at(r) && checkPalindrome_mem(str, l + 1, r - 1);
  if (ans == 0) // to correct the print logic
    ans = 2;

  return arr[l][r] = ans;
}

// dp bottom up approach
void checkPalindrome_dp(std::string str, std::pair<int, int> queries[],
                        int len) {
  int strLength = str.length();
  bool dp[strLength][strLength];

  // we will fill entire matrix first and then fetch required l and r values
  // flow will be same as wines problem
  int l = 0;
  int r = 0;
  for (; l < strLength; l++, r++) {
    // we gonna ignore when l>r
    // at first l==r and creates a diagonal element where..
    dp[l][r] = true;
    int temp = l;

    l--;
    while (l >= 0) {
      // when only 2 element
      if ((r - l) == 1)
        dp[l][r] = str.at(l) == str.at(r);

      dp[l][r] = str.at(l) == str.at(r) && dp[l + 1][r - 1];
      l--;
    }
    l = temp;
  }
  // no we have everything filled just return results
  for (int i = 0; i < len; i++) {
    std::cout << std::boolalpha << dp[queries[i].first][queries[i].second]
              << std::endl;
  }
}

// driver program
void checkPalindrome(std::string str, std::pair<int, int> queries[], int len) {

  // bruteforce approach becuse calling same thing for every pair
  for (int i = 0; i < len; i++) {
    std::cout << std::boolalpha
              << checkPalindrome_bf(str, queries[i].first, queries[i].second)
              << std::endl;
    print(checkPalindrome_mem(str, queries[i].first, queries[i].second));
  }
}

int main(void) {
  std::string str;
  std::cin >> str;

  int len;
  std::cin >> len;

  std::pair<int, int> queries[len];
  for (int i = 0; i < len; i++) {
    std::cin >> queries[i].first;
    std::cin >> queries[i].second;
  }

  checkPalindrome(str, queries, len);
  std::cout << "==============" << std::endl;
  checkPalindrome_dp(str, queries, len);
}

// I know its Saphagetti code this time :p