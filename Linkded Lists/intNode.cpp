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
        // lil bug found: waits for  new value if existing input isn't stripped
    int data;
    std::cin >> data;
    char ch = std::cin.peek();

    Node* head = nullptr;
    Node* tail = nullptr;
    while(ch != '\n'){
        Node* newNode = new Node(data);
        // means this is the very first node
        if(head == nullptr){
            head = newNode;
            tail = newNode;
        }
        else{
        // update existing tail
            tail->next = newNode;
            tail = newNode;
        }
        std::cin >> data;
        ch = std::cin.peek();
    }
    //appending the last element
    if(head != nullptr) // if more than 1 item is present
        tail->next = new Node(data);
    else
        head = new Node(data);
        
    return head;
}
