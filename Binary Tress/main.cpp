#include "binaryTreeNode.h"
#include <iostream>
#include <queue>

// print BTree level wise
template <class T> void printTree(BinaryTreeNode<T> *root) {
  // checck if root isn't null
  if (root == nullptr)
    return;

  // create queue
  std::queue<BinaryTreeNode<T> *> pendingNodes;
  pendingNodes.push(root);

  // starting from root print and push each child
  while (!pendingNodes.empty()) {
    BinaryTreeNode<T> *front = pendingNodes.front();
    pendingNodes.pop();

    std::cout << front->data << ": ";

    if (front->left != nullptr) {
      std::cout << 'L' << front->left->data;
      pendingNodes.push(front->left);
    }
    if (front->right != nullptr) {
      std::cout << 'R' << front->right->data;
      pendingNodes.push(front->right);
    }
    std::cout << std::endl;
  }
}

// -1 is terminating condition so can't be used as data
template <class T> BinaryTreeNode<T> *takeInput() {
  // take root node data
  T rootData;
  std::cout << "Enter root data:" << std::endl;
  std::cin >> rootData;
  if (rootData == -1) {
    return nullptr;
  }
  // create root node and a queue
  BinaryTreeNode<T> *root = new BinaryTreeNode<T>(rootData);
  std::queue<BinaryTreeNode<T> *> pendingNodes;
  pendingNodes.push(root);
  // traverse till end, take input, create tree and fill queue
  while (!pendingNodes.empty()) {
    // get first element from queue and fill L and R element
    BinaryTreeNode<T> *front = pendingNodes.front();
    pendingNodes.pop();
    // left node
    T leftChildData;
    std::cout << "Enter left child data of " << front->data << ":" << std::endl;
    std::cin >> leftChildData;
    if (leftChildData != -1) {
      BinaryTreeNode<T> *child = new BinaryTreeNode<T>(leftChildData);
      front->left = child;
      pendingNodes.push(child);
    }
    // right node
    T rightChildData;
    std::cout << "Enter right child data of " << front->data << ":"
              << std::endl;
    std::cin >> rightChildData;
    if (rightChildData != -1) {
      BinaryTreeNode<T> *child = new BinaryTreeNode<T>(rightChildData);
      front->right = child;
      pendingNodes.push(child);
    }
  }

  return root;
}

int main(void) {
  BinaryTreeNode<int> *root = takeInput<int>();
  printTree(root);
  return 0;
}
