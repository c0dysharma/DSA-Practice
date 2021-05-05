#include <iostream>

class Node {
public:
  int data;
  Node *next;

  // constructor
  Node(int data) : data(data), next(nullptr) {}
};

// printing node func
void print(const Node *head) {
  while (head != nullptr) {
    std::cout << head->data << ' ';
    head = head->next;
  }
  std::cout << std::endl;
}

// Creates new linked list
Node *createLinkedList(void) {
  // takes space seperated input untill newLine character is appeared
  // lil bug found: waits for  new value if existing input isn't stripped
  int data;
  std::cin >> data;
  char ch = std::cin.peek();

  Node *head = nullptr;
  Node *tail = nullptr;
  while (ch != '\n') {
    Node *newNode = new Node(data);
    // means this is the very first node
    if (head == nullptr) {
      head = newNode;
      tail = newNode;
    } else {
      // update existing tail
      tail->next = newNode;
      tail = newNode;
    }
    std::cin >> data;
    ch = std::cin.peek();
  }
  // appending the last element
  if (head != nullptr) // if more than 1 item is present
    tail->next = new Node(data);
  else
    head = new Node(data);

  return head;
}

// returns length of the list
int getLength(Node *head) {
  // recursive approach
  // base case
  if (head == nullptr)
    return 0;

  // recursive call
  int smallOutput = getLength(head->next);
  // smaller Calculation
  return smallOutput + 1;

  // iterative approch
  // int len = 0;
  // while(head!=nullptr){
  //     head = head->next;
  //     len++;
  // }
  // return len;
}
// reach ith node
Node *reachBeforeINode(Node *head, int i) {
  int lengthOfList = getLength(head);
  if (i > lengthOfList)
    return head;

  for (int j = 0; j < i - 1; j++) {
    head = head->next;
  }

  return head;
}

// print i-th position
void printIthPosition(Node *head, int i) {
  head = reachBeforeINode(head, i);
  std::cout << head->next->data << std::endl;
}

// insert at i-th position
Node *insertIthNode(Node *head, int data, int i) {
  // recursive approach
  // special case:
  if (head == nullptr) {
    if (i != 0)
      return head;
    // add element at ending
    return new Node(data);
  }

  // smaller Calculation and recursive call
  if (i == 0) {
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
    return head;
  } else {
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
Node *deleteIthNode(Node *head, int i) {
  // recursicve approach
  // base case
  if (head == nullptr)
    return head;

  // smaller calculation
  if (i == 0) {
    Node *nodeToBeDeleted = head;
    head = head->next;
    delete nodeToBeDeleted;
    return head;
  }

  // recursive call
  head->next = deleteIthNode(head->next, i - 1);
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

// free up dynamically allocated list
void deleteList(Node *head) {
  // base case
  if (head == nullptr)
    return;

  // recursive call
  deleteList(head->next);
  // smaller calculation
  delete head;
}

// search node: returns -1 if not found otherwise index of value
int findNode(Node *head, int val) {
  int count = -1;
  while (head != nullptr) {
    count++;
    if (head->data == val)
      return count;
    head = head->next;
  }
  return -1;
}

// Appened last n items to first
Node *appenedNtoFirst(Node *head, int n) {
  // get to the n-1 node's index
  int len = getLength(head);
  if (n <= 0 || n >= len)
    return head;

  int curr = len - n - 1;
  // reach on the curr index
  Node *temp = reachBeforeINode(head, curr);
  temp = temp->next;
  // getting new  head
  Node *head2 = temp->next;
  // breaking the list into 2 parts
  temp->next = nullptr;
  // combining both lists
  // reach on end of head2
  temp = head2;
  while (temp->next != nullptr) {
    temp = temp->next;
  }
  temp->next = head;
  return head2;
}

// remove duplicates from ordered list
Node *removeDuplicates(Node *head) {
  if (head->next == nullptr)
    return head;

  // recursive call
  Node *t2 = removeDuplicates(head->next);
  // smaller calcculation
  if (head->data == t2->data) {
    Node *nextNode = t2->next;
    // t2 = t2->next;
    delete t2;
    head->next = nextNode;
  }
  return head;
}

// print reverse LL
void printReverseLL(Node *head) {
  // base case
  if (head == nullptr)
    return;

  // recursive call
  printReverseLL(head->next);
  // smaller caclculation
  std::cout << head->data << ' ';
}

// reverse the linked list
Node *returnReverseLL(Node *head) {
  // base case
  if (head == nullptr || head->next == nullptr)
    return head;

  // reucursive call
  Node *smallerOutput = returnReverseLL(head->next);
  // smaller Calculation

  // reach at the end of LL
  Node* temp = smallerOutput;
  while(temp->next != nullptr){
    temp = temp->next;
  }
  // move first element to the end
  temp->next = head;
  head->next = nullptr;

  return smallerOutput;
}

// check palindrome
bool checkPalindrome(Node *head) {
  Node *head2 = returnReverseLL(head);

  while (head != nullptr) {
    if (head->data == head2->data) {
      head = head->next;
      head2 = head2->next;
      continue;
    }
    deleteList(head2);
    return false;
  }
  deleteList(head2);
  return true;

  // // dividing the LL in two parts
  // int mid = getLength(head)/2;
  // // reaching on mid point
  // int count = 0;
  // Node* temp = head;
  // while(count < mid-1){
  //   count++;
  //   temp = temp->next;
  // }
  // Node* head2 = temp->next;
  // temp->next = nullptr;

  // // reverse 2nd part

  // // comparing both LLs
  // while(head->data != head2->data){
  //   head = head->next;
  //   head2 = head2->next;
  //   // if only one pointer reached till end;
  //   if(head==nullptr ^ head2==nullptr)
  //     return true;
  // }
  // return false;
}

// merge two shorted LL
Node *mergeTwoSortedLL(Node *head1, Node *head2) {
  // recursive apporoach

  // base case
  if (head1 == nullptr)
    return head2;
  else if (head2 == nullptr)
    return head1;

  Node *result = nullptr;
  // recursive call with smaller calculation
  if (head1->data <= head2->data) {
    result = head1;
    result->next = mergeTwoSortedLL(head1->next, head2);
  } else {
    result = head2;
    result->next = mergeTwoSortedLL(head1, head2->next);
  }

  return result;

  // iterative approach
  // // if any LL is null return the other one
  // if (head1 == nullptr)
  //   return head2;
  // if (head2 == nullptr)
  //   return head1;

  // // Initial Values
  // Node *finalHead = nullptr;
  // if (head1->data <= head2->data) {
  //   finalHead = head1;
  //   head1 = head1->next;
  // } else {
  //   finalHead = head2;
  //   head2 = head2->next;
  // }
  // Node *finalTail = finalHead;

  // // main loop
  // while (head1 != nullptr && head2 != nullptr) {
  //   if (head1->data <= head2->data) {
  //     finalTail->next = head1;
  //     finalTail = finalTail->next;
  //     head1 = head1->next;
  //   } else {
  //     finalTail->next = head2;
  //     finalTail = finalTail->next;
  //     head2 = head2->next;
  //   }
  // }
  // // when one or both of LL are exhausted
  // if (head1 == nullptr)
  //   finalTail->next = head2;

  // else
  //   finalTail->next = head1;

  // return finalHead;
}

// merge sort
Node *mergeSort(Node *head) {
  // base case: when we have 0 or 1 element
  if (head == nullptr || head->next == nullptr)
    return head;

  // helper values
  // Node *head1 = head;
  int mid = getLength(head) / 2;
  Node *beforeMidHead = reachBeforeINode(head, mid);

  // divide the LL
  Node *head2 = beforeMidHead->next;
  beforeMidHead->next = nullptr;

  // recursive call
  Node *a = mergeSort(head);
  Node *b = mergeSort(head2);

  // smaller Calculation
  return mergeTwoSortedLL(a, b);
}