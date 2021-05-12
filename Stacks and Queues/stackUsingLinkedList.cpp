#include <iostream>
template <class T> class Stack;
template <class T> class Node {
private:
  T data;
  Node *next;

public:
  Node(T value) : data{value}, next{nullptr} {};
  friend class Stack<T>;
};

template <class T> class Stack {
private:
  Node<T> *head;
  int size;
  void deleteList(Node<T> *head) {
    // base case
    if (head == nullptr)
      return;

    // recursive call
    deleteList(head->next);
    // smaller calculation
    delete head;
    head = nullptr;
  }

public:
  // constructor
  Stack() : head{nullptr}, size{0} {}

  // deconstructor
  ~Stack() { deleteList(head); }

  // other functions
  bool isEmpty() { return size == 0; }

  T top() {
    if (size != 0)
      return head->data;
    return 0;
  }

  T pop() {
    if (size != 0) {
      T headData = head->data;
      Node<T> *nodeToBeDeleted = head;
      head = head->next;
      delete nodeToBeDeleted;
      size--;
      return headData;
    }
    return 0;
  }

  void push(T val) {
    Node<T> *newNode = new Node<T>(val);
    newNode->next = head;
    head = newNode;
    size++;
  }
};

int main(void) {
  // int example
  Stack<int> s1;
  s1.push(10);
  s1.push(20);
  s1.push(100);
  s1.push(200);
  std::cout << s1.top() << std::endl;
  std::cout << s1.pop() << std::endl;
  std::cout << s1.top() << std::endl;
  std::cout << s1.pop() << std::endl;

  // char example
  Stack<char> s2;
  s2.push('w');
  s2.push('x');
  s2.push('y');
  std::cout << s2.top() << std::endl;
  std::cout << s2.pop() << std::endl;
  std::cout << s2.top() << std::endl;
  std::cout << s2.top() << std::endl;
  return 0;
}