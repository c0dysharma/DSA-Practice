#include <vector>
using namespace std;

template <class T> class TreeNode {
public:
  T data;
  vector<TreeNode<T> *> children;
  // constructor
  TreeNode(T data) : data{data} {}
  // deconstructor
  ~TreeNode(){
    for(auto child: children){
      delete child;
    }
  }
};