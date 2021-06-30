#include "binaryTreeNode.h"
#include <algorithm>
#include <climits>
#include <iostream>
#include <list>
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

// return pair of minimum(first)  and maximum(second)
template <class T> std::pair<int, int> getMinMax(BinaryTreeNode<T> *root) {
  // using pair's first for minimum and second for maximum
  // edge case and base case
  if (root == nullptr) {
    std::pair<int, int> p;
    p.first = INT_MAX;
    p.second = INT_MIN;

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
  ans.second = std::max(root->data, std::max(lmax, rmax));

  return ans;
}

// return sum of every nodes
template <class T> int sumOfAllNodes(BinaryTreeNode<T> *root) {
  if (root == nullptr)
    return 0;
  return root->data + sumOfAllNodes(root->left) + sumOfAllNodes(root->right);
}

// return true if difference between height of left and right tree of
// each node is <= 1
template <class T> std::pair<int, bool> isBalanced(BinaryTreeNode<T> *root) {
  // using first as height of tree and second bool as tree is balanced or not
  // till now
  if (root == nullptr) {
    std::pair<int, bool> p;
    p.first = 0;
    p.second = true;
    return p;
  }

  std::pair<int, bool> leftPair = isBalanced(root->left);
  std::pair<int, bool> rightPair = isBalanced(root->right);

  std::pair<int, bool> ansPair;
  // balancing is true only when both left and right pair are true
  // and diffrence between their height is also <= 1
  ansPair.second = leftPair.second && rightPair.second &&
                   std::abs(leftPair.first - rightPair.first) <= 1;
  ansPair.first = std::max(leftPair.first, rightPair.first) + 1;

  return ansPair;
}

// level order printing
template <class T> void levelOrderPrint(BinaryTreeNode<T> *root) {
  if (root == nullptr)
    return;

  std::queue<BinaryTreeNode<T> *> pendingNodes;
  pendingNodes.push(root);
  pendingNodes.push(nullptr);

  while (true) {
    BinaryTreeNode<T> *currentNode = pendingNodes.front();
    pendingNodes.pop();

    if (currentNode == nullptr) {
      std::cout << std::endl;
      // pendingNodes.pop();
      if (pendingNodes.empty())
        break;
      else
        pendingNodes.push(nullptr);
      continue;
    }
    std::cout << currentNode->data << ' ';
    if (currentNode->left != nullptr)
      pendingNodes.push(currentNode->left);
    if (currentNode->right != nullptr)
      pendingNodes.push(currentNode->right);
  }
}

// remove leaf nodes
template <class T> BinaryTreeNode<T> *removeLeafNodes(BinaryTreeNode<T> *root) {
  // edge case
  if (root == nullptr)
    return root;

  // if there is no child its leaf node
  if (root->left == nullptr && root->right == nullptr) {
    delete root;
    return nullptr;
  }

  root->left = removeLeafNodes(root->left);
  root->right = removeLeafNodes(root->right);
  return root;
}

//  create linked list
template <class T>
std::vector<std::list<T> *> returnLinkedList(BinaryTreeNode<T> *root) {

  // helper DS
  std::vector<std::list<T> *> listvec;
  std::queue<BinaryTreeNode<T> *> pendingNodes;

  // edge case
  if (root == nullptr) {
    return listvec;
  }

  pendingNodes.push(root);
  pendingNodes.push(nullptr);

  int currentLevel = 0;
  while (true) {
    BinaryTreeNode<T> *currentNode = pendingNodes.front();
    pendingNodes.pop();

    // when we reached end of a level
    if (currentNode == nullptr) {
      if (pendingNodes.empty())
        break;
      else {
        currentLevel++;
        pendingNodes.push(nullptr);
      }
      continue;
    }

    if (listvec.size() < currentLevel + 1) {
      // current level's list is not present
      // create new list and add to vector
      std::list<T> *newList = new std::list<T>;
      listvec.push_back(newList);
    }
    // list added or already existed just add data in list
    listvec.at(currentLevel)->push_back(currentNode->data);

    // add children if not null in queue
    if (currentNode->left != nullptr)
      pendingNodes.push(currentNode->left);
    if (currentNode->right != nullptr)
      pendingNodes.push(currentNode->right);
  }
  return listvec;
}

// print non-siblings node's data
template <class T> void printNonSiblings(BinaryTreeNode<T> *root) {
  if (root == nullptr)
    return;

  // only print data if only one child exists
  if (root->left == nullptr ^ root->right == nullptr) {
    if (root->right != nullptr)
      std::cout << root->right->data << ' ';

    if (root->left != nullptr)
      std::cout << root->left->data << ' ';
  }

  if (root->left != nullptr)
    printNonSiblings(root->left);

  if (root->right != nullptr)
    printNonSiblings(root->right);
}

// Binary search tree - functions starting bst needs sorted tree
// i.e smaller data should appear on left and larger on right

// return true if found else returns false
template <class T> bool bstFindNode(BinaryTreeNode<T> *root, T data) {
  // base case
  if (root == nullptr)
    return false;

  if (data == root->data)
    return true;
  else if (data < root->data)
    return bstFindNode(root->left, data);
  else
    return bstFindNode(root->right, data);
}

// print all the elments in range min and max
template <class T> void bstPrintInRange(BinaryTreeNode<T> *root, T min, T max) {
  // base case
  if (root == nullptr)
    return;

  if (root->data < min)
    bstPrintInRange(root->right, min, max);
  else if (root->data > max)
    bstPrintInRange(root->left, min, max);
  else {
    // data is in/on the range
    std::cout << root->data << ' ';
    bstPrintInRange(root->left, min, max);
    bstPrintInRange(root->right, min, max);
  }
}

// returns true if given tree is BST else false
template <class T>
bool isBST(BinaryTreeNode<T> *root, T min = INT_MIN, T max = INT_MAX) {
  if (root == nullptr)
    return true;

  if (root->data < min || root->data > max)
    return false;

  bool isLeftBST = isBST(root->left, min, root->data - 1);
  bool isRightBST = isBST(root->right, root->data, max);

  return isLeftBST && isRightBST;
}

// create and returns BST from sorted array
template <class T>
BinaryTreeNode<T> *createBSTfromArray(T arr[], int startIndex, int stopIndex) {
  // base case
  if (startIndex > stopIndex) {
    return nullptr;
  }
  int rootIndex = (startIndex + stopIndex) / 2;
  BinaryTreeNode<T> *root = new BinaryTreeNode<T>(arr[rootIndex]);
  root->left = createBSTfromArray(arr, startIndex, rootIndex - 1);
  root->right = createBSTfromArray(arr, rootIndex + 1, stopIndex);

  return root;
}

// create sorted linked list from BST
template <class T> std::list<T> *bstCreateLL(BinaryTreeNode<T> *root) {
  // base case
  if (root == nullptr)
    return nullptr;

  std::list<T> *finalList = bstCreateLL(root->left);

  if (finalList != nullptr)
    finalList->push_back(root->data);
  else {
    finalList = new std::list<T>;
    finalList->push_back(root->data);
  }

  std::list<T> *rightList = bstCreateLL(root->right);
  if (rightList != nullptr)
    finalList->push_back(rightList->front());

  return finalList;
}

// returns path from root to the node with data
template <class T>
std::vector<T> *getRootToNodePath(BinaryTreeNode<T> *root, T data) {
  // base case
  if (root == nullptr)
    return nullptr;

  if (root->data == data) {
    std::vector<T> *itsMe = new std::vector<T>;
    itsMe->push_back(root->data);
    return itsMe;
  }

  // we need to call both sides since function doesn't only expects as bst
  // but only if we haven't found the data node
  std::vector<T> *leftOutput = getRootToNodePath(root->left, data);
  if (leftOutput != nullptr) {
    leftOutput->push_back(root->data);
    return leftOutput;
  }

  std::vector<T> *rightOutput = getRootToNodePath(root->right, data);
  if (rightOutput != nullptr) {
    rightOutput->push_back(root->data);
    return rightOutput;
  }

  // when none returns (node not found)
  return nullptr;
}

// attach duplicates to the left
template <class T> void attachDuplicateLeft(BinaryTreeNode<T> *root) {
  if (root == nullptr)
    return;

  // create duplicate of root node
  BinaryTreeNode<T> *newNode = new BinaryTreeNode<T>(root->data);
  // attach newNode to left and current left to newNode
  BinaryTreeNode<T> *left = root->left;
  root->left = newNode;
  newNode->left = left;

  // recursive call on both sides
  attachDuplicateLeft(newNode->left);
  attachDuplicateLeft(root->right);
}

// adds elements to the vector inorder fashion
template <class T>
void addElementsToVector(BinaryTreeNode<T> *root, std::vector<T> &vec) {
  if (root == nullptr)
    return;

  addElementsToVector(root->left, vec);
  vec.push_back(root->data);
  addElementsToVector(root->right, vec);
}

// prints all the pair which sums up to S
void printPairs(BinaryTreeNode<int> *root, int S) {
  if (root == nullptr)
    return;

  // create vector of the all elements
  std::vector<int> vec;
  addElementsToVector(root, vec);
  // sort the elements
  std::sort(vec.begin(), vec.end());

  // algo to find and print sum
  int i = 0;
  int j = vec.size() - 1;
  while (i <= j) {
    int iVal = vec.at(i);
    int jVal = vec.at(j);

    if (iVal + jVal == S) {
      std::cout << iVal << ' ' << jVal << std::endl;
      i++;
      j--;
    } else if (iVal + jVal < S)
      i++;
    else
      j--;
  }
}

// return LCA(Lowest Common ancestor) of N1 and N2 node, -1 if not found
template <class T> T returnLSC(BinaryTreeNode<T> *root, T N1, T N2) {
  if (root == nullptr)
    return -1;

  // if we found any node on root thats the ancestor
  if (root->data == N1)
    return N1;
  if (root->data == N2)
    return N2;

  // recursive call
  T leftN = returnLSC(root->left, N1, N2);
  T rightN = returnLSC(root->right, N1, N2);

  // cases
  // when none of the node found
  if (leftN == -1 && rightN == -1)
    return -1;

  // when both nodes are found
  if (leftN != -1 && rightN != -1)
    return root->data;

  // when exactly one node is found
  if (leftN == -1 ^ rightN == -1) {
    if (leftN != -1)
      return leftN;

    if (rightN != -1)
      return rightN;
  }
  // never reach here
  return -1;
}

// return pair with min,max,isBST, maximum BST height
struct largestBSTstruct {
public:
  int min;
  int max;
  bool bst;
  int height;
};

template <class T> largestBSTstruct getLargetBST(BinaryTreeNode<T> *root) {
  largestBSTstruct final;

  if (root == nullptr) {
    final.bst = true;
    final.height = 0;
    final.min = INT_MAX;
    final.max = INT_MIN;

    return final;
  }

  // doing recursive call on both sides
  largestBSTstruct leftData = getLargetBST(root->left);
  largestBSTstruct rightData = getLargetBST(root->right);

  // whole tree is bst only when these conditions satsfies
  bool currBST = leftData.max < root->data && rightData.min > root->data;
  final.bst = leftData.bst && rightData.bst && currBST;

  // increase height count only if it is bst
  final.height = (final.bst) ? std::max(leftData.height, rightData.height) + 1
                             : std::max(leftData.height, rightData.height);

  // minimum/maximum amoung root's data, left's data, right's data
  final.min = std::min(root->data, std::min(leftData.min, rightData.min));
  final.max = std::max(root->data, std::max(leftData.max, rightData.max));

  return final;
}

// replace everynode with sum of itself and all the node greater than itself
int bstReplaceLargerSum(BinaryTreeNode<int> *root, int sum = 0) {
  if (root == nullptr)
    return 0;

  // we will do recursive call in reverse inorder(right, root, left) fashion
  // since we need sum or root's parent's right bcz its already greater than
  // itself and we are returning int(sum of children) because they are going to
  // changed
  int rightSum = bstReplaceLargerSum(root->right, sum);
  int rootData = root->data;
  root->data = rootData + rightSum + sum;
  int leftSum = bstReplaceLargerSum(root->left, root->data);

  return leftSum + rightSum + rootData;
}

// print root to leaf node path that sum to k
void printSumKtoLeafNode(BinaryTreeNode<int> *root, int k,
                         std::string path = "") {
  // edge case
  if (root == nullptr)
    return;

  // add current node to the path only if it doesn't exceed k val
  if (root->data <= k) {
    path += std::to_string(root->data);
    path += ' ';
  } else
    return;

  // base case
  // check first if its a leaf node
  if (root->left == nullptr && root->right == nullptr) {
    if (root->data == k)
      std::cout << path << std::endl;
  }

  // recursive call on both sides with decreasing k
  printSumKtoLeafNode(root->left, k - (root->data), path);
  printSumKtoLeafNode(root->right, k - (root->data), path);
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
// 4 2 6 1 3 5 7 -1 -1 -1 -1 -1 -1 -1 -1
// 4 2 6 1 30 5 7 -1 -1 -1 -1 -1 -1 -1 -1
int main(void) {
  BinaryTreeNode<int> *root = takeInput<int>();
  printTree(root);
  delete root;
  return 0;
}
