#include "Trie.h"
#include <iostream>

int main(void) {
  Trie test;
  test.insertWord("aa");
  test.insertWord("abc");
  test.insertWord("def");

  std::cout << test.searchWord("abc") << std::endl;
  test.removeWord("abc");
  std::cout << test.searchWord("abc") << std::endl;
  std::cout << test.searchWord("aa") << std::endl;
}