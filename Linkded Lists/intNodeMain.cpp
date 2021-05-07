#include "intNode.cpp"

int main(void) {
  // simple printing
  std::cout << "Enter first Linked List sepearted by space 😎🆒\n";
  Node *head1 = createLinkedList();
  std::cout << std::endl;

  std::cout << "⚠ My indexing starts at 0 🕶 🤏\n";
  std::cout << "You entered following list with lenghth " << getLength(head1)
            << std::endl;
  print(head1);
  std::cout<<std::endl;

  // operations
  std::cout << "Which node should I print? 🤔\n";
  int val;
  std:: cin >> val;
  std::cout << "this node is: ";
  printIthPosition(head1,val);
  std::cout << std::endl;

  std::cout << "Tell me a node data real quick...💨\n";
  std::cin >> val;
  head1 = insertIthNode(head1,val,0);
  std::cout << "Ok I appended at first see...👀\n";
  print(head1);
  std::cout << std::endl;
  head1 = deleteIthNode(head1,0);

  std::cout << "Now I removed 😏\n";
  print(head1);
  std::cout << std::endl;

  std::cout << "I am gonna find a node for you 🔍\n";
  std::cin >> val;
  std::cout << "Node is at index " << findNode(head1,val) << std::endl;
  std::cout << std::endl;

  std::cout << "Look at the sorted Linked List🥵\n";
  head1 = mergeSort(head1);
  print(head1);
  std::cout << std::endl;

  std::cout << "Look at the list UNIQUE and REVERSED 🧝‍♀️🧝‍♂️\n";
  head1 = removeDuplicates(head1);
  head1 = returnReverseLL(head1);
  print(head1);
  std::cout << std::endl;

  std::cout << "I am gonna swap first and last element🔀\n";
  head1 = swapIJNode(head1,0,getLength(head1)-1);
  print(head1);
  std::cout << std::endl;

  // flexing (¬‿¬)
  std::cout << "I can do much more💪 but am lazy to do all😪... see you \n";
  std::cout << std::endl;

  // cleaning up mess
  deleteList(head1);

  return 0;
}