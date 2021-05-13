#include <iostream>
template <class T> class Queue;
template <class T> class Node {
private:
  T data;
  Node *next;

public:
  Node(T value) : data{value}, next{nullptr} {};
  friend class Queue<T>;
};

template <class T> class Queue {
private:
  Node<T> *head;
  Node<T> *tail;
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
  Queue() : head{nullptr}, tail{nullptr}, size{0} {}

  // deconstructor
  ~Queue() { deleteList(head); }

  // other functions
  bool isEmpty() { return size == 0; }

  T getSize() { return size; }

  T front() { return head->data; }

  void enqueue(T val) {
    // list is empty
    if (isEmpty()) {
      head = new Node<T>(val);
      tail = head;
      size++;
      return;
    }
    Node<T> *newNode = new Node<T>(val);
    tail->next = newNode;
    tail = newNode;
    size++;
  }

  T dequeue() {
    if (isEmpty())
      return 0;

    T headData = head->data;
    Node<T> *nodeToBeDeleted = head;
    head = head->next;

    delete nodeToBeDeleted;
    size--;
    return headData;
  }
};

int main(void) {
  Queue<int> q;
  q.enqueue(10);
  q.enqueue(20);
  q.enqueue(30);
  std::cout << q.dequeue() << std::endl;
  std::cout << q.dequeue() << std::endl;

  std::cout << q.getSize() << std::endl;
  std::cout << q.front() << std::endl;
  std::cout << q.dequeue() << std::endl;
  std::cout << q.dequeue() << std::endl;
  return 0;
}