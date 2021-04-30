#pragma once

struct Node {
  int data;
  Node *next;
  Node(int val) : data(val), next(nullptr) {}
};
void print(const Node *head);
Node *createLinkedList(void);
int getLength(Node *head);
void printIthPosition(Node *head, int i);
Node *insertIthNode(Node *head, int data, int i);
Node *deleteIthNode(Node *head, int i);
void deleteList(Node *head);