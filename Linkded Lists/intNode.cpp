#include <iostream>

class Node{
    public:

    int data;
    Node* next;

    //constructor
    Node(int data)
    :data(data), next(nullptr){}
};

// pirinting node func
void print(const Node *head){
    while (head != nullptr){
        std::cout << head->data << ' ';
        head = head->next;
    }
    std::cout << std::endl;
}

Node* createLinkedList(void){
    // takes space seperated input untill newLine character is appeared
    int data;
    std::cin >> data;
    char ch = std::cin.peek();

    Node* head = nullptr;
    Node* tail = nullptr;
    while(ch != '\n'){
        Node* newNode = new Node(data);
        // means this is the very first node
        if(head == nullptr)
            head = newNode;
        else{
            // we need to reach end of the list to add new element
            tail = head;
            while (tail->next != nullptr){
                tail = tail->next;
            }tail->next = newNode;
        }
        std::cin >> data;
        ch = std::cin.peek();
    }
    //appending the last element
    tail->next->next = new Node(data);
    return head;
}
