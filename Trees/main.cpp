#include "TreeNode.h"
#include <iostream>
#include <queue>

template <class T> TreeNode<T> *takeInput() {
  // Take root node data
  std::cout << "Enter root node data: ";
  int rootData;
  std::cin >> rootData;

  // create root node
  TreeNode<T> *root = new TreeNode<T>(rootData);
  // create queue and add root node to it
  std::queue<TreeNode<T> *> pendingNodes;
  pendingNodes.push(root);
  // iterate through queue untill size=0
  while (!pendingNodes.empty()) {
    // get front on queue
    TreeNode<T> *front = pendingNodes.front();
    pendingNodes.pop();
    // get count of child of front and take children
    int childCount;
    std::cout << "How many child does " << front->data << " have?: ";
    std::cin >> childCount;

    for (int i = 0; i < childCount; i++) {
      int childData;
      std::cout << "Enter " << i << "th child data: ";
      std::cin >> childData;

      // create and add children node to tree and push to queue
      TreeNode<T> *child = new TreeNode<T>(childData);
      front->children.push_back(child);
      pendingNodes.push(child);
    }
  }
  // return root node
  return root;
}

template <class T> void printTree(TreeNode<T> *root) {
  if (root == nullptr)
    return;

  std::cout << root->data << ": ";
  for (auto child : root->children) {
    std::cout << child->data << ", ";
  }
  std::cout << std::endl;

  for (auto child : root->children) {
    printTree(child);
  }
}

// Prints tree level wise
template <class T> void printTreeLevel(TreeNode<T> *root) {
  // checck if root isn't null
  if (root == nullptr)
    return;
  // create queue
  std::queue<TreeNode<T> *> pendingNodes;
  pendingNodes.push(root);
  // starting from root print and push each child
  while (!pendingNodes.empty()) {
    TreeNode<T> *front = pendingNodes.front();
    pendingNodes.pop();

    std::cout << front->data << ": ";
    for (auto child : front->children) {
      std::cout << child->data << ", ";
      pendingNodes.push(child);
    }
    std::cout << std::endl;
  }
}

template <class T> int countNodes(TreeNode<T> *root) {
  // check if root insn't null
  if (root == nullptr)
    return 0;

  // recursively add value to ans variable
  int ans = 1; // bcz root is here
  for (auto child : root->children) {
    ans += countNodes(child);
  }
  return ans;
}

int sumOfNodes(TreeNode<int> *root) {
  // check if root insn't null
  if (root == nullptr)
    return 0;

  // recursively add value to ans variable
  int ans = root->data; // bcz root is here
  for (auto child : root->children) {
    ans += sumOfNodes(child);
  }
  return ans;
}

int largestData(TreeNode<int> *root) {
  // check if root insn't null
  if (root == nullptr)
    return 0;

  int rootData = root->data;
  int childData = 0;
  for (auto child : root->children) {
    int smallAns = largestData(child);
    childData = childData > smallAns ? childData : smallAns;
  }
  return rootData > childData ? rootData : childData;
}

template <class T> int getLevel(TreeNode<T> *root) {
  // check if root insn't null
  if (root == nullptr)
    return 0;

  int levels = 0;
  for (auto child : root->children) {
    int childLevel = getLevel(child);
    levels = levels > childLevel ? levels : childLevel;
  }
  return levels + 1;
}

template <class T> void printDepth(TreeNode<T> *root, int k) {
  // check if root insn't null
  if (root == nullptr)
    return;

  if (k == 0) {
    std::cout << root->data << std::endl;
    return;
  }

  for (auto child : root->children) {
    printDepth(child, k - 1);
  }
}

template <class T> int countLeaf(TreeNode<T> *root) {
  // check if root insn't null
  if (root == nullptr)
    return 0;

  if (root->children.empty()) {
    return 1;
  }
  int leafCount = 0;
  for (auto child : root->children) { // check if root insn't null
    leafCount += countLeaf(child);
  }
  return leafCount;
}

// post root traversal
template <class T> void postTraverse(TreeNode<T> *root) {
  // check if root insn't null
  if (root == nullptr) {
    return;
  }

  for (auto child : root->children) {
    postTraverse(child);
  }
  std::cout << root->data << " ";
}

// pre root traversal
template <class T> void preTraverse(TreeNode<T> *root) {
  // check if root insn't null
  if (root == nullptr) {
    return;
  }
  std::cout << root->data << " ";
  for (auto child : root->children) {
    preTraverse(child);
  }
}

// delete tree
template <class T> void deleteTree(TreeNode<T> *root) {
  // check if root insn't null
  if (root == nullptr) {
    return;
  }

  for (auto child : root->children) {
    deleteTree(child);
  }
  delete root;
}

// find x
template <class T> bool isPresent(TreeNode<T> *root, T x) {
  // check if root insn't null
  if (root == nullptr) {
    return false;
  }

  // base case
  if (root->data == x) {
    return true;
  }
  // recursive call
  bool found = false;
  for (auto child : root->children) {
    found = isPresent(child, x);
  }
  return found;
}

template <class T> int countGreaterThanX(TreeNode<T> *root, T x) {
  // check if root insn't null
  if (root == nullptr) {
    return 0;
  }
  int count = 0;
  for (auto child : root->children) {
    count += countGreaterThanX(child, x);
  }
  if (root->data > x)
    return count + 1;
  return count;
}

template <class T> class Pair {
public:
  T nodeData;
  T nodeSum;
};

template <class T> Pair<T> largestSum(TreeNode<T> *root) {
  Pair<T> rootPair;
  rootPair.nodeData = root->data;
  rootPair.nodeSum = root->data;

  for (auto child : root->children) {
    rootPair.nodeSum += child->data;
  }

  for (auto child : root->children) {
    Pair<T> childPair = largestSum(child);
    if (childPair.nodeSum > rootPair.nodeSum) {
      rootPair.nodeData = childPair.nodeData;
      rootPair.nodeSum = childPair.nodeSum;
    }
  }
  return rootPair;
}

template <class T> bool compareTress(TreeNode<T> *rootA, TreeNode<T> *rootB) {
  // edge cases
  if (rootA == nullptr || rootB == nullptr ||
      rootA->children.size() != rootB->children.size())
    return false;

  if (rootA->data != rootB->data)
    return false;

  bool childEqual = true;
  for (int i = 0; i < rootA->children.size(); i++) {
    childEqual = compareTress(rootA->children[i], rootB->children[i]);
    if (childEqual == false)
      return false;
  }
  return childEqual;
}

template <class T> T nextLargerValue(TreeNode<T>*root, int N){
  // check if root insn't null
  if (root == nullptr) {
    return 0;
  }

  T rootVal = (root->data > N) ? root->data : 0;
  T childVal;

  for(auto child:root->children){
    childVal = nextLargerValue(child,N);
    
    if(rootVal == 0 && childVal>0)
      rootVal = childVal;

    if(childVal<rootVal)
      rootVal = childVal;
  }
  return rootVal;
}

void replaceWithDepth(TreeNode<int>* root, int depth=0){
  // check if root insn't null
  if (root == nullptr) {
    return;
  }
  root->data = depth;
  for(auto child:root->children){
    replaceWithDepth(child,depth+1);
  }
}

int main(void) {
  TreeNode<int> *root = takeInput<int>();
  printTreeLevel(root);
  // std::cout << countNodes(root) << std::endl;
  // std::cout << sumOfNodes(root) << std::endl;
  // std::cout << largestData(root) << std::endl;
  // std::cout << getLevel(root) << std::endl;
  // printDepth(root,2);
  // std::cout << countLeaf(root) << std::endl;
  // preTraverse(root);
  // int x;
  // std::cin >> x;
  // std::cout << std::boolalpha << isPresent(root, x) << std::endl;
  // std::cout << countGreaterThanX(root, x) << std::endl;
  // std::cout << largestSum(root).nodeData << std::endl;
  // TreeNode<int> *root2 = takeInput<int>();
  // std::cout << boolalpha << compareTress(root, root2) << std::endl;
  // std::cout << nextLargerValue(root,x) << std::endl;
  replaceWithDepth(root);
  printTreeLevel(root);
  // delete root2;
  delete root;
  return 0;
}