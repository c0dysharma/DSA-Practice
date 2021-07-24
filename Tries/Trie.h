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

  ~TrieNode() {
    for (int i = 0; i < 26; i++) {
      delete children[i];
      children[i] = nullptr;
    }
  }
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

  bool __searchWord(TrieNode *root, std::string word) {
    // base case
    if (word.size() == 0) {
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
    return __searchWord(child, word.substr(1));
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

public:
  Trie() { root = new TrieNode('\0'); }
  void insertWord(std::string word) { __insertWord(root, word); }
  bool searchWord(std::string word) { return __searchWord(root, word); }
  void removeWord(std::string word) { __removeWord(root, word); }
  ~Trie() { delete root; }
};