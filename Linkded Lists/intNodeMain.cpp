#include "intNode.cpp"

int main(void) {
  Node *head = createLinkedList();
  print(head);

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
  std::cout << std::boolalpha << checkPalindrome(head) << std::endl;
  deleteList(head);

  return 0;
}