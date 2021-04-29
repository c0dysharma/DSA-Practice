#include "intNode.cpp"

int main(void)
{
    Node *head = createLinkedList();
    print(head);

    int data, i;
    std::cin >>data>> i;
    head = insertIthNode(head,data,i);
    // head = deleteIthNode(head,i);
    print(head);
    head = deleteIthNode(head, i);
    print(head);
    std::cout << getLength(head) << std::endl;

    return 0;
}