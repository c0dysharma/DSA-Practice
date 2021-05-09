#pragma once
#include <ostream>
template <class T> class LinkedList;
template <class T> class Node {
private:
  T data;
  Node *next;
  friend class LinkedList<T>;

public:
  Node(T data) : data{data}, next{nullptr} {}
  template <class U>
  friend std::ostream &operator<<(std::ostream &stream,
                                  const LinkedList<U> &list);
};

template <class T> class LinkedList {
private:
  Node<T> *head;
  Node<T> *tail;
  void deleteList(Node<T> *head);

public:
  LinkedList();
  ~LinkedList();
  void addNode(T val);
  int length();
  void deleteNode(int i);
  template <class U>friend std::ostream &operator<<(std::ostream &stream, const LinkedList<U> &list);
  // can have much or operatoins
};

