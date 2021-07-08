#include <vector>

class PriorityQueue {
  private:
  std::vector<int> queue;

public:
  int getSize() { return queue.size(); }
  bool isEmpty() { return queue.size() == 0; }
  int getMin() { return (isEmpty()) ? 0 : queue.at(0); }

  void insert(int element) {
    // add the element to the end
    queue.push_back(element);
    // tranverse till we reach top
    int childIndex = queue.size() - 1;
    while (childIndex > 0) {
      int parentIndex = (childIndex - 1) / 2;

      if (queue[childIndex] < queue[parentIndex]) // we need to swap
        std::swap(queue[childIndex], queue[parentIndex]);
      else // we have to break its alredy there
        break;

      // after swaping now
      childIndex = parentIndex;
    }
  }

  int removeMin() {
    // get the min value before removing
    int ans = queue[0];
    queue[0] = queue.back();
    queue.pop_back();

    // traverse till we get to last node
    int parentIndex = 0;
    int childIndex1 = 2 * parentIndex + 1;
    int childIndex2 = 2 * parentIndex + 2;
    while (childIndex1 < queue.size()) {

      // get the correct minimum Index
      int minIndex = parentIndex;
      if (queue[childIndex1] < queue[minIndex])
        minIndex = childIndex1;

      if (queue[childIndex2] < queue[minIndex] && childIndex2 < queue.size())
        minIndex = childIndex2;

      // if parent index is smallest we have nothing to do
      if (minIndex == parentIndex)
        break;

      // swap otherwise
      std::swap(queue[parentIndex], queue[minIndex]);

      parentIndex = minIndex;
      childIndex1 = 2 * parentIndex + 1;
      childIndex2 = 2 * parentIndex + 2;
    }

    return ans;
  }
};
