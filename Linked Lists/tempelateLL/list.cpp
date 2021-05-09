#include "list.hpp"
#include <iostream>

// create first node or add element to non empty node
template <class T> void LinkedList<T>::addNode(T val) {
  // increase length count
  length++;
  // checks if ll is empty
  if (head == nullptr) {
    head = new Node<T>(val);
    tail = head;
    return;
  }
  // if its not
  Node<T> *newNode = new Node<T>(val);
  tail->next = newNode;
  tail = newNode;
}

// returns length of the list
template <class T> int LinkedList<T>::getLength() {
  return length;
}

// delete ith node
template <class T> void LinkedList<T>::deleteNode(int i) {
  // decrease lenghth count
  length--;
  Node<T> *nodeToBeDeleted;
  if (i == 1) {
    nodeToBeDeleted = head;
    head = head->next;
    delete nodeToBeDeleted;
    return;
  }

  int len = getLength();
  // when node to be deleted is beyond list
  if (i > len)
    return;

  // reach at i-1  node
  Node<T> *temp = head;
  int count = 1;
  while (count != i - 1) {
    temp = temp->next;
    count++;
  }
  nodeToBeDeleted = temp->next;
  temp->next = nodeToBeDeleted->next;
  delete nodeToBeDeleted;
}

// helper function for destructor to erase the linked list from memory
template <class T> void LinkedList<T>::deleteList(Node<T> *head) {
  // base case
  if (head == nullptr)
    return;

  // recursive call
  LinkedList<T>::deleteList(head->next);
  // smaller calculation
  delete head;
  head = nullptr;
}
// constructor
template <class T> LinkedList<T>::LinkedList() {
  head = nullptr;
  tail = nullptr;
}

// deconstructor
template <class T> LinkedList<T>::~LinkedList() { deleteList(head); }

// utility function for printing linked list
template <class U>
std::ostream &operator<<(std::ostream &stream, const LinkedList<U> &list) {
  Node<U> *temp = list.head;
  while (temp != nullptr) {
    stream << temp->data << ' ';
    temp = temp->next;
  }
  return stream;
}

// helps in creating LinkedList seperated by spaces
template <class U> LinkedList<U> &createList(void) {
  // takes space seperated input untill newLine character is appeared
  // lil bug found: waits for  new value if existing input isn't stripped
  U data;
  std::cin >> data;
  char ch = std::cin.peek();

  LinkedList<U> *head = new LinkedList<U>();
  while (ch != '\n') {
    head->addNode(data);

    std::cin >> data;
    ch = std::cin.peek();
  }
  // adding last element as weel
  head->addNode(data);
  return *head;
}