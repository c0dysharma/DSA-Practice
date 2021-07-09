#include <iostream>

// helper insert function
void helpMeInsert(int *arr, int size, int endIndex = 1) {
  //base case
  // if the array is empty there is nothing to do
  if (size == 0 || size == 1 || endIndex == size) {
    return;
  }

  // smaller calculation
  // we will start from comparing 2nd element
  int childIndex = endIndex;
  while (childIndex > 0) {
    int parentIndex = (childIndex - 1) / 2;

    if (arr[childIndex] > arr[parentIndex]) // we need to swap
      std::swap(arr[childIndex], arr[parentIndex]);
    else
      break;

    childIndex = parentIndex;
  }
  // recursive call
  helpMeInsert(arr, size, endIndex + 1);
}

void helpMeRemove(int *arr, int size) {
  // base case
  if (size == 0 || size == 1)
    return;

  // smaller calculation
  // send the min element to last
  std::swap(arr[0], arr[size - 1]);
  // we won't work on that now so
  size--;

  int parentIndex = 0;
  int childIndex1 = 2 * parentIndex + 1;
  int childIndex2 = 2 * parentIndex + 2;
  while (childIndex1 < size) {

    // get the correct minimum Index
    int maxIndex = parentIndex;
    if (arr[childIndex1] > arr[maxIndex])
      maxIndex = childIndex1;

    if (arr[childIndex2] > arr[maxIndex] && childIndex2 < size)
      maxIndex = childIndex2;

    // if parent index is smallest we have nothing to do
    if (maxIndex == parentIndex)
      break;

    // swap otherwise
    std::swap(arr[parentIndex], arr[maxIndex]);

    parentIndex = maxIndex;
    childIndex1 = 2 * parentIndex + 1;
    childIndex2 = 2 * parentIndex + 2;
  }
  //recursive call
  helpMeRemove(arr, size);
}

// will sort the array in assending order
void inplaceHeapSort(int *arr, int size) {
  // inser element in heapOrder form
  helpMeInsert(arr, size);
  helpMeRemove(arr, size);
}

int main() {
  int len;
  std::cin >> len;
  int arr[len];
  for (int i = 0; i < len; i++) {
    std::cin >> arr[i];
  }

  inplaceHeapSort(arr, len);

  for (int i = 0; i < len; i++) {
    std::cout << arr[i] << ' ';
  }
  std::cout << std::endl;

  return 0;
}