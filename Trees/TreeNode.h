#include <vector>
using namespace std;

template <class T> class TreeNode {
public:
  T data;
  vector<TreeNode<T> *> childern;
  // constructor
  TreeNode(T data) : data{data} {}
};