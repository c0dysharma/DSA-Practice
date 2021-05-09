#include "list.cpp"
#include <iostream>

int main(void) {

    // int list
  std::cout << "Am goona create a <int> linked list shoot values...\n";
  LinkedList<int> l1 = createList<int>();
  std::cout << std::endl;

  std::cout << "You entered....\n";
  std::cout << l1 << std::endl;
  std::cout << std::endl;

  std::cout << "I can delete 1 item for you tell me which place\n";
  int i;
  std::cin >> i;
  l1.deleteNode(i);
  std::cout << std::endl;

  std::cout << "Now the list looks like this: \n";
  std::cout << l1 << std::endl;
  std::cout << std::endl;

// strings list
//   LinkedList<string> l2 = createList<string>();

// We can create any datatype list with templates
  return 0;
}

/*
I figured compiler needs function defination of tempelates while compiling to
create desired function/class when we are calling them so..
I can't just import list.hpp which has only declaratiion

Info source :
https://stackoverflow.com/questions/1111440/undefined-reference-error-for-template-method
*/