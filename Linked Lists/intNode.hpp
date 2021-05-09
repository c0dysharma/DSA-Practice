#pragma once
//Node itself
class Node {
public:
  int data;
  Node *next;

  // constructor
  Node(int data) : data(data), next(nullptr) {}
};

//Prototypes
void print(const Node *head);
Node *createLinkedList(void);
int getLength(Node *head);
Node *reachBeforeINode(Node *head, int i);
void printIthPosition(Node *head, int i);
Node *insertIthNode(Node *head, int data, int i);
Node *deleteIthNode(Node *head, int i);
void deleteList(Node *head);
int findNode(Node *head, int val);
Node *appenedNtoFirst(Node *head, int n);
Node *removeDuplicates(Node *head);
void printReverseLL(Node *head);
Node *returnReverseLL(Node *head);
bool checkPalindrome(Node *head);
Node *mergeTwoSortedLL(Node *head1, Node *head2);
Node *mergeSort(Node *head);
void appendLast(Node *&linkedList, int data, Node *&head, Node *&tail);
Node *returnOddBeforeEven(Node *head);
void deleteNNodeAfterM(Node *head, int M, int N);
Node *swapIJNode(Node *head, int i, int j);
Node *kreverse(Node *head, int k);
Node *bubbleSort(Node *head);