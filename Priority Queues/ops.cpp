#include <iostream>
#include <queue>

// prints k smallest elements
void printMinKElements(int *arr, int len, int k) {
  if (len == 0)
    return;
  std::priority_queue<int> pq;

  // we gonna start with just first k elements
  for (int i = 0; i < k; i++) {
    pq.push(arr[i]);
  }

  // we now just gonna replace remaining elements of array with largest of pq
  for (int i = k; i < len; i++) {
    if (pq.top() > arr[i]) {
      pq.pop();
      pq.push(arr[i]);
    }
  }

  // now pq contains k smallest elements we can now just print
  for (int i = 0; i < k; i++) {
    std::cout << pq.top() << std::endl;
    pq.pop();
  }
}

// print k largest elements
void printMaxKElements(int *arr, int len, int k) {
  if (len == 0)
    return;
  std::priority_queue<int, std::vector<int>, std::greater<int>> pq;

  // we gonna start with just first k elements
  for (int i = 0; i < k; i++) {
    pq.push(arr[i]);
  }

  // we now just gonna replace remaining elements of array with smallest of pq
  for (int i = k; i < len; i++) {
    if (pq.top() < arr[i]) {
      pq.pop();
      pq.push(arr[i]);
    }
  }

  // now pq contains k largest elements we can now just print
  for (int i = 0; i < k; i++) {
    std::cout << pq.top() << std::endl;
    pq.pop();
  }
}

// returns true if array satisfies heap order property
bool isHeap(int *arr, int len) {
  int parentIndex = 0;
  int childIndex1 = 2 * parentIndex + 1;
  int childIndex2 = 2 * parentIndex + 2;

  while (childIndex1 < len) {
    if (arr[childIndex1] > arr[parentIndex])
      return false;
    if (childIndex2 < len)
      if (arr[childIndex2] > arr[parentIndex])
        return false;
      else
        ;
    // beacuse if the second child is out of bound every other parent's child
    // will also be hence considered as end of search
    else
      break;

    parentIndex++;
    childIndex1 = 2 * parentIndex + 1;
    childIndex2 = 2 * parentIndex + 2;
  }
  // everything is fine
  return true;
}

// print kth largest element in array
void printKthLargest(int *arr, int len, int k) {
  // create pq to sort in O(nLogn)
  std::priority_queue<int> pq;
  for (int i = 0; i < len; i++) {
    pq.push(arr[i]);
  }
  // pop till we get kth element
  for (int i = 0; i < k - 1; i++) {
    pq.pop();
  }

  // now top element of pq is our required element
  std::cout << pq.top() << std::endl;
}

int main(void) {
  int len;
  std::cin >> len;
  int arr[len];

  for (int i = 0; i < len; i++) {
    std::cin >> arr[i];
  }

  //   std::cout << isHeap(arr, len) << std::endl;
  int k;
  std::cin >> k;
  //   printMaxKElements(arr, len, k);
  printKthLargest(arr, len, k);
  return 0;
}