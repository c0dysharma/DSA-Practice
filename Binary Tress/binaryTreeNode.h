template <class T> class BinaryTreeNode {
public:
  T data;
  BinaryTreeNode<T> *left;
  BinaryTreeNode<T> *right;
  // constructor
  BinaryTreeNode(T data) : data{data}, left{nullptr}, right{nullptr} {}
  // Deconstrutor
  ~BinaryTreeNode() {
    delete left;
    delete right;
  }
};