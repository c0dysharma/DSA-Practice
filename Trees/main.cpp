#include <iostream>
#include "TreeNode.h"

template <class T> void printTree(TreeNode<T> *root) {
  if (root == nullptr)
    return;

  std::cout << root->data << ":";
  for(auto child: root->childern){
      std::cout << child->data << ", ";
  }std::cout << std::endl;

  for(auto child: root->childern){
      printTree(child);
  }
}

int main(void){
    TreeNode<int>* root = new TreeNode<int>(10);
    TreeNode<int>* child1 = new TreeNode<int>(20);
    TreeNode<int> *child2 = new TreeNode<int>(30);

    root->childern.push_back(child1);
    root->childern.push_back(child2);

    printTree(root);
    return 0;
}