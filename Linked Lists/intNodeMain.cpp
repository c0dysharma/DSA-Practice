#include "intNode.hpp"
#include <iostream>

int main(void) {
  // simple printing
  std::cout << "Enter first Linked List sepearted by space ๐๐\n";
  Node *head1 = createLinkedList();
  std::cout << std::endl;

  std::cout << "โ  My indexing starts at 0 ๐ถ ๐ค\n";
  std::cout << "You entered following list with lenghth " << getLength(head1)
            << std::endl;
  print(head1);
  std::cout<<std::endl;

  // operations
  std::cout << "Which node should I print? ๐ค\n";
  int val;
  std:: cin >> val;
  std::cout << "this node is: ";
  printIthPosition(head1,val);
  std::cout << std::endl;

  std::cout << "Tell me a node data real quick...๐จ\n";
  std::cin >> val;
  head1 = insertIthNode(head1,val,0);
  std::cout << "Ok I appended at first see...๐\n";
  print(head1);
  std::cout << std::endl;
  head1 = deleteIthNode(head1,0);

  std::cout << "Now I removed ๐\n";
  print(head1);
  std::cout << std::endl;

  std::cout << "I am gonna find a node for you ๐\n";
  std::cin >> val;
  std::cout << "Node is at index " << findNode(head1,val) << std::endl;
  std::cout << std::endl;

  std::cout << "Look at the sorted Linked List๐ฅต\n";
  head1 = mergeSort(head1);
  print(head1);
  std::cout << std::endl;

  std::cout << "Look at the list UNIQUE and REVERSED ๐งโโ๏ธ๐งโโ๏ธ\n";
  head1 = removeDuplicates(head1);
  head1 = returnReverseLL(head1);
  print(head1);
  std::cout << std::endl;

  std::cout << "I am gonna swap first and last element๐\n";
  head1 = swapIJNode(head1,0,getLength(head1)-1);
  print(head1);
  std::cout << std::endl;

  // flexing (ยฌโฟยฌ)
  std::cout << "I can do much more๐ช but am lazy to do all๐ช... see you \n";
  std::cout << std::endl;

  // cleaning up mess
  deleteList(head1);

  return 0;
}