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

// helper call for next function
class ElementInfo {
public:
  int element;
  int elementIndex;
  int arrayIndex;

  ElementInfo(int element, int elementIndex, int arrayIndex)
      : element{element}, elementIndex{elementIndex}, arrayIndex{arrayIndex} {}
};
bool operator<(const ElementInfo &lhs, const ElementInfo &rhs) {
  return lhs.element > rhs.element;
}

// merge K sorted arrays into one
std::vector<int> mergeKSortedArrays(std::vector<std::vector<int>> container) {
  // get the initial values and add to pq
  std::priority_queue<ElementInfo> pq;
  for (int i = 0; i < container.size(); i++) {
    pq.emplace(container[i][0], 0, i);
  }

  // now pq has smallest element on top
  std::vector<int> mergedArray;
  while (!pq.empty()) {
    mergedArray.push_back(pq.top().element);
    int elemIndex = pq.top().elementIndex;
    int arrIndex = pq.top().arrayIndex;
    elemIndex++;
    // remove the element
    pq.pop();
    if (elemIndex != container[arrIndex].size())
      pq.emplace(container[arrIndex][elemIndex], elemIndex, arrIndex);
  }

  return mergedArray;
}

// print median at every element
void printMedians(int *arr, int len) {
  std::priority_queue<int> maxHeap;
  std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

  maxHeap.push(arr[0]);
  std::cout << maxHeap.top() << std::endl;

  for (int i = 1; i < len; i++) {
    // add based on value
    if (arr[i] < maxHeap.top())
      maxHeap.push(arr[i]);
    else
      minHeap.push(arr[i]);

    int maxHeapSize = maxHeap.size();
    int minHeapSize = minHeap.size();

    // balance the shits
    if (maxHeapSize - minHeapSize > 1) {
      int temp = maxHeap.top();
      minHeap.push(temp);
      maxHeap.pop();
    }
    if (minHeapSize - maxHeapSize > 1) {
      int temp = minHeap.top();
      maxHeap.push(temp);
      minHeap.pop();
    }

    maxHeapSize = maxHeap.size();
    minHeapSize = minHeap.size();

    // find and print median
    // if(maxHeapSize == 1 && minHeapSize == 0)
    // std::cout << maxHeap.top() << std::endl;

    if ((maxHeapSize + minHeapSize) % 2 == 0)
      std::cout << (maxHeap.top() + minHeap.top()) / 2 << std::endl;
    else {
      if (maxHeapSize > minHeapSize)
        std::cout << maxHeap.top() << std::endl;
      else
        std::cout << minHeap.top() << std::endl;
    }
  }
}

// return time taken till k index person get ticket. 1 unit time is taken
//  when actually ticket is given no time taken in removing and adding person
int buyTicket(int *arr,int len, int k) {
  int timeTaken = 0;
  std::queue<int> q;
  std::priority_queue<int> pq;

  // fill up our queues
  for(int i = 0; i<len; i++){
    q.push(i);
    pq.push(arr[i]);
  }

  while(!pq.empty()){
    // we got the value with its priority
    if(arr[q.front()] == pq.top()){
      timeTaken++;
      if(q.front() == k)
        break;
    
      q.pop();
      pq.pop();
    }else{
      // its not the value required send it to back
      int temp = q.front();
      q.pop();
      q.push(temp);
    }
  }

  return timeTaken;

}
int main(void) {
  int len;
  std::cin >> len;

  // std::vector<std::vector<int>> container;
  // for (int i = 0; i < K; i++) {
  //   int len;
  //   std::cin >> len;
  //   std::vector<int> arr;
  //   for (int i = 0; i < len; i++) {
  //     int temp;
  //     std::cin >> temp;
  //     arr.push_back(temp);
  //   }

  //   container.push_back(arr);
  // }

  // std::vector<int> mergedArray = mergeKSortedArrays(container);
  // for (int a : mergedArray) {
  //   std::cout << a << ' ';
  // }
  // std::cout << std::endl;

  int arr[len];
  for (int i = 0; i < len; i++) {
    std::cin >> arr[i];
  }
  int k;
  std::cin >> k;

  std::cout << buyTicket(arr,len,k) << std::endl;
  // printMedians(arr, K);

  return 0;
}