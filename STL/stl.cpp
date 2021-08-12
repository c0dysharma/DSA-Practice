#include <algorithm>
#include <iostream>

int main(void) {
  int arr[] = {10, 20, 50, 40, 80, 40};
  int n = sizeof(arr) / sizeof(int);

  int key;
  std::cin >> key;

  // return iterator to the first occurance O(n) coz its just a linear search
  auto it = std::find(arr, arr + n, key);
  if (it - arr != n)
    std::cout << "Index is " << it - arr << std::endl;
  else
    std::cout << "Not Found!\n";

  int arr2[] = {10, 20, 40, 40, 80, 100};
  n = sizeof(arr2) / sizeof(int);

  // Overall time complexity O(logn) + O(logn) = O(logn)

  // binary search O(logn) only if data is found
  if (std::binary_search(arr2, arr2 + n, key)) {
    // return iterator to first occurance >= key
    auto lb = std::lower_bound(arr2, arr2 + n, key);
    // return iterator to first occurance stricly > key
    auto ub = std::upper_bound(arr2, arr2 + n, key);

    std::cout << "First Ocuurance at " << lb - arr2 << std::endl;
    std::cout << "Total frequency is " << ub - lb << std::endl;
  } else
    std::cout << "Not Found!\n";
}