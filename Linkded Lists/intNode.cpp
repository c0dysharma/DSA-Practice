#include <iostream>

class Node{
    public:

    int data;
    Node* next;

    //constructor
    Node(int data)
    :data(data), next(nullptr){}
};

// printing node func
void print(const Node *head){
    while (head != nullptr){
        std::cout << head->data << ' ';
        head = head->next;
    }
    std::cout << std::endl;
}

// Creates new linked list 
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

// returns length of the list
int getLength(Node* head){
// recursive approach
    // base case
    if(head == nullptr)
        return 0;
    
    //recursive call
    int smallOutput = getLength(head->next);
    //smaller Calculation
    return smallOutput+1;

// iterative approch
    // int len = 0;
    // while(head!=nullptr){
    //     head = head->next;
    //     len++;
    // }
    // return len;
}

// print i-th position 
void printIthPosition(Node* head, int i){
    int lengthOfList = getLength(head);
    if(i > lengthOfList)
        return;
    
    // Node* temp = head;
    for(int j = 0; j<i; j++){
        head = head->next;
    }std::cout << head->data << std::endl;
}

// insert at i-th position
Node *insertIthNode(Node* head, int data, int i){
// recursive approach
    // special case:
    if(head == nullptr){
        if(i!=0)
            return head;
        //add element at ending
        return new Node(data);
    }

    // smaller Calculation and recursive call
    if(i==0){
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
        return head;
    }else{
        head->next = insertIthNode(head->next, data, i - 1);
        return head;
    }

// iterative approach
    // Node *newNode = new Node(data);
    // // if we we to add at first position
    // if(i==0){
    //     newNode->next = head;
    //     head = newNode;
    //     return head;
    // }
    // // insert at any other position
    // int count = 0;
    // // reach at tail-1 position for insertion
    // Node* temp = head;
    // while(count < i-1 && temp != nullptr){
    //     temp = temp->next;
    //     count++;
    // }
    // // if position to insert is beyond maximium legth exit
    // if(temp == nullptr)
    //     return head;

    // // insertion
    // newNode->next = temp->next;
    // temp->next = newNode;

    // return head;

}

// delete i-th node
Node* deleteIthNode(Node* head, int i){
// recursicve approach
    //base case
    if(head == nullptr)
        return head;
    
    //smaller calculation
    if(i==0){
        Node *nodeToBeDeleted = head;
        head = head->next;
        delete nodeToBeDeleted;
        return head;
    }

    // recursive call
    head->next = deleteIthNode(head->next,i-1);
    return head;

// iterative approach
    // // if nodeToBe deleted is first
    // if(i==0){
    //     Node *nodeToBeDeleted = head;
    //     head = head->next;
    //     delete nodeToBeDeleted;
    //     return head;
    // }
    // // getting tail-i position
    // int count = 0;
    // Node* temp = head;
    // while(count < i-1 && temp != nullptr){
    //     temp = temp->next;
    //     count++;
    // }
    // // when we reached beyond length of list exit
    // if(temp == nullptr)
    //     return head;
    
    // // deletation
    // Node* nodeToBeDeleted = temp->next;
    // Node* nextNode = nodeToBeDeleted->next;
    // temp->next = nextNode;
    // delete nodeToBeDeleted;
    // return head;
}