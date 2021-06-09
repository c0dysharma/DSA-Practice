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

// return number of nodes present
template <class T> int countNodes(BinaryTreeNode<T> *root) {
  if (root == nullptr)
    return 0;
  return 1 + countNodes(root->left) + countNodes(root->right);
}

// returns true if node is present in tree or not
template <class T> bool isPresent(BinaryTreeNode<T> *root, T data) {
  if (root == nullptr)
    return false;

  if (isPresent(root->left, data) || isPresent(root->right, data))
    return true;

  if (root->data == data)
    return true;

  return false;
}

// return height of a tree
template <class T> int getHeight(BinaryTreeNode<T> *root) {
  if (root == nullptr)
    return 0;

  int leftChildLevel = getHeight(root->left);
  int rightChildLevel = getHeight(root->right);

  return 1 + std::max(leftChildLevel, rightChildLevel);
}

// mirror nodes of a tree
template <class T> void mirrorTree(BinaryTreeNode<T> *root) {
  if (root == nullptr)
    return;

  mirrorTree(root->left);
  mirrorTree(root->right);
  BinaryTreeNode<int> *temp = root->left;
  root->left = root->right;
  root->right = temp;
}

// inorder traverse print
template <class T> void inorderPrint(BinaryTreeNode<T> *root) {
  if (root == nullptr)
    return;

  inorderPrint(root->left);
  std::cout << root->data << ' ';
  inorderPrint(root->right);
}

// preorder traverse print
template <class T> void preorderPrint(BinaryTreeNode<T> *root) {
  if (root == nullptr)
    return;

  std::cout << root->data << ' ';
  preorderPrint(root->left);
  preorderPrint(root->right);
}

// postorder traverse print
template <class T> void postorderPrint(BinaryTreeNode<T> *root) {
  if (root == nullptr)
    return;

  postorderPrint(root->left);
  postorderPrint(root->right);
  std::cout << root->data << ' ';
}

// get height and diameter of tree
template <class T>
std::pair<int, int> getHeightDiamter(BinaryTreeNode<T> *root) {
  // using pair's first for height and second for diameter
  if (root == nullptr) {
    std::pair<int, int> p;
    p.first = 0;
    p.second = 0;

    return p;
  }

  std::pair<int, int> leftSideData = getHeightDiamter(root->left);
  std::pair<int, int> rightSideData = getHeightDiamter(root->right);

  int lh = leftSideData.first;
  int rh = rightSideData.first;
  int ld = leftSideData.second;
  int rd = rightSideData.second;

  std::pair<int, int> ansPair;
  ansPair.first = 1 + std::max(lh, rh);
  ansPair.second = std::max(lh + rh, std::max(ld, rd));

  return ansPair;
}

template <class T> std::pair<int, int> getMinMax(BinaryTreeNode<T> *root){
  // using pair's first for minimum and second for maximum
  // edge case and base case
  if (root == nullptr) {
    std::pair<int, int> p;
    p.first = INT16_MAX;
    p.second = INT16_MIN;

    return p;
  }

  std::pair<int, int> leftSideData = getMinMax(root->left);
  std::pair<int, int> rightSideData = getMinMax(root->right);

  int lmin = leftSideData.first;
  int rmin = rightSideData.first;
  int lmax = leftSideData.second;
  int rmax = rightSideData.second;

  std::pair<int, int> ans;
  ans.first = std::min(root->data, std::min(lmin, rmin));
  ans.second = std::max(root->data,std::max(lmax, rmax));

  return ans;

}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
int main(void) {
  BinaryTreeNode<int> *root = takeInput<int>();
  printTree(root);
  // mirrorTree(root);
  // printTree(root);
  // int x;
  // std::cin >> x;
  // std::cout << std::boolalpha << isPresent(root,x) << std::endl;
  // std::cout << countNodes(root) << std::endl;
  // std::cout << getHeight(root) << std::endl;
  // inorderPrint(root);
  // std::cout << std::endl;
  // preorderPrint(root);
  // std::cout << std::endl;
  // postorderPrint(root);
  // std::cout << std::endl;
  std::pair<int, int> ans = getHeightDiamter(root);
  std::cout << "Height: " << ans.first << std::endl;
  std::cout << "Diameter: " << ans.second << std::endl;

  std::pair<int, int> minmax = getMinMax(root);
  std::cout << "Min: " << minmax.first << std::endl;
  std::cout << "Max: " << minmax.second << std::endl;

  delete root;
  return 0;
}
