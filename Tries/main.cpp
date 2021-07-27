#include "Trie.h"
#include <algorithm>
#include <iostream>

bool isPalindrome(Trie data, int len, std::string words[]) {
  // add all words first
  for (int i = 0; i < len; i++) {
    data.insertWord(words[i]);
  }
  // check if their reverse exists or not
  for (int i = 0; i < len; i++) {
    std::reverse(words[i].begin(), words[i].end());
    if (data.searchWord(words[i]))
      return true;
    else
      continue;
  }
  return false;
}

int main(void) {
  int len;
  std::cin >> len;

  Trie test;
  std::string words[len];
  for (int i = 0; i < len; i++) {
    std::cin >> words[i];
    test.insertWord(words[i]);
  }

  std::string w;
  std::cin >> w;
  test.autoComplete(w);
}