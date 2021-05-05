#include "intNode.cpp"

int main(void) {
  Node *head = createLinkedList();
  // print(head);
  // Node *head2 = createLinkedList();

  //   int data, i;
  //   std::cin >> data >> i;
  //   head = insertIthNode(head, data, i);
  //   // head = deleteIthNode(head,i);
  //   print(head);
  //   head = deleteIthNode(head, i);
  //   print(head);
  //   std::cout << getLength(head) << std::endl;

  //   int val;
  //   std::cin >> val;
  //   std::cout << findNode(head, val) << std::endl;
  //   int i;
  //   std::cin >> i;
  //   head = appenedNtoFirst(head, i);
  //   print(head);

  // head = removeDuplicates(head);
  // print(head);
  // printReverseLL(head);
  // Node* finalLL = mergeTwoSortedLL(head, head2);
  // print(finalLL);
  // printIthPosition(finalLL,2);
  // deleteList(finalLL);
  // Node* sortedLL = mergeTwoSortedLL(head,head2);
  // print(sortedLL);
  // deleteList(sortedLL);
  Node* head1 = returnReverseLL(head);
  print(head1);
  deleteList(head1);
  return 0;
}