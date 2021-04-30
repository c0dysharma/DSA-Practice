#include "structNode.hpp"
#include <iostream>

int main(){
    Node *head = createLinkedList();
    print(head);
    
    int data, i;
    std::cin >> data >> i;
    head = insertIthNode(head,data,i);
    print(head);

    head=deleteIthNode(head,i);
    print(head);

    printIthPosition(head,i);
    deleteList(head);

    return 0;
}