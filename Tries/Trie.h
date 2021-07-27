#include <iostream>
#include <string>

class TrieNode {
public:
  char val;
  TrieNode **children;
  bool isTerminal;

  TrieNode(char val) {
    this->val = val;
    children = new TrieNode *[26];
    for (int i = 0; i < 26; i++) {
      children[i] = nullptr;
    }
    isTerminal = false;
  }

  // ~TrieNode() {
  //   for (int i = 0; i < 26; i++) {
  //     delete children[i];
  //     children[i] = nullptr;
  //   }
  // }
};

class Trie {
  TrieNode *root;

  void __insertWord(TrieNode *root, std::string word) {
    // base case
    if (word.size() == 0) {
      root->isTerminal = true;
      return;
    }

    // small calculation
    int index = word.at(0) - 'a';
    TrieNode *child;
    if (root->children[index] != nullptr)
      child = root->children[index];
    else {
      child = new TrieNode(word.at(0));
      root->children[index] = child;
    }

    // recursive call
    __insertWord(child, word.substr(1));
  }

  bool __searchWord(TrieNode *root, std::string word, bool isSuffix = false) {
    // base case
    if (word.size() == 0) {
      if (isSuffix)
        return true;

      if (root->isTerminal == true)
        return true;
      return false;
    }

    // small calculation
    int index = word.at(0) - 'a';
    TrieNode *child = root->children[index];

    if (root->children[index] == nullptr)
      return false;
    // recursive call
    return __searchWord(child, word.substr(1), isSuffix);
  }

  void __removeWord(TrieNode *root, std::string word) {
    // base case
    if (word.length() == 0) {
      root->isTerminal = false;
      return;
    }

    // small calculation
    int index = word.at(0) - 'a';
    TrieNode *child;

    if (root->children[index] != nullptr)
      child = root->children[index];
    else {
      // word doesn't exists
      return;
    }

    // recursive call
    __removeWord(child, word.substr(1));

    // deallocate space if useless
    if (child->isTerminal == false) {
      // check if any child exists or not
      for (int i = 0; i < 26; i++) {
        if (child->children[i] != nullptr)
          return;
      }

      // clear it out
      delete child;
      root->children[index] = nullptr;
    }
  }

  void __autoComplete(TrieNode *root, std::string word,
                      std::string output = "") {

    // base case
    if (root == nullptr)
      return;

    // if (root->val == '\0' &&)
    //   return;

    // smaller caclulation
    if (root->val != word.at(word.length() - 1))
      output += root->val;

    if (root->isTerminal)
      std::cout << word + output << std::endl;

    // recursive call
    for (int i = 0; i < 26; i++) {
      __autoComplete(root->children[i], word, output);
    }
  }

public:
  Trie() { root = new TrieNode('\0'); }
  // now just use isSuffix=true for enabling suffix trie
  // support(pattern matching)

  void insertWord(std::string word, bool isSuffix = false) {
    if (isSuffix) {
      int wordLen = word.length();
      for (int i = 0; i < wordLen; i++) {
        __insertWord(root, word.substr(i));
      }
    } else
      __insertWord(root, word);
  }
  // now just use isSuffix=true for enabling suffix trie
  // support(pattern matching)
  bool searchWord(std::string word, bool isSuffix = false) {
    return __searchWord(root, word, isSuffix);
  }
  // bool isTerminal(){return root->isTerminal;}
  // char thisChar(){return root->val;}
  // TrieNode** getChild(){return root->children;}

  void removeWord(std::string word) { __removeWord(root, word); }
  void autoComplete(std::string word) {

    TrieNode *lastNode = root;
    int len = word.length();
    for (int i = 0; i < len; i++) {
      int index = word.at(i) - 'a';
      lastNode = lastNode->children[index];
    }
    if (lastNode != nullptr)
      __autoComplete(lastNode, word);
    std::cout << "Nothing to Suggest Here!" << std::endl;
  }
  // ~Trie() { delete root; }
};