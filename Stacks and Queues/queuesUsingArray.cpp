#include <iostream>
const int initialCapacity = 5;

template <class T> class Queue {
private:
  T *data;
  int nextIndex;
  int firstIndex;
  int size;
  int capacity;

public:
  // construtor
  Queue() {
    capacity = initialCapacity;
    data = new T[capacity];
    nextIndex = 0;
    firstIndex = -1;
    size = 0;
  }

  // deconstructor
  ~Queue() { delete[] data; }

  // other operations
  void enqueue(T val) {
    // check if queue is full
    if (size == capacity) {
      // copy existing elements in double size queue
      T *newData = new T[2 * capacity];
      int j = 0;
      for (int i = firstIndex; i < capacity; i++) {
        newData[j++] = data[i];
      }
      for (int i = 0; i < firstIndex; i++) {
        newData[j++] = data[i];
      }

      delete[] data;
      data = newData;
      nextIndex = capacity;
      capacity *= 2;
      firstIndex = 0;
    }
    data[nextIndex] = val;
    // to move circularly
    nextIndex = (nextIndex + 1) % capacity;
    size++;
    if (firstIndex == -1)
      firstIndex = 0;
  }

  T dequeue() {
    if (isEmpty()) {
      std::cout << "Queue is empty..." << std::endl;
      return 0;
    }
    T ans = data[firstIndex];
    size--;
    firstIndex++;
    // reseting the vars
    if (size == 0) {
      firstIndex = -1;
      nextIndex = 0;
    }
    return ans;
  }

  int getSize() { return size; }

  bool isEmpty() { return size == 0; }

  T front() {
    if (isEmpty()) {
      std::cout << "Queue is empty..." << std::endl;
      return 0;
    }
    return data[firstIndex];
  }
};

int main(void) {
  Queue<int> q1;
  q1.enqueue(10);
  q1.enqueue(20);
  q1.enqueue(30);
  q1.enqueue(40);
  q1.enqueue(50);
  // std::cout << q1.dequeue() << std::endl;
  q1.enqueue(60);

  std::cout << q1.front() << std::endl;
  std::cout << q1.dequeue() << std::endl;
  std::cout << q1.dequeue() << std::endl;
  std::cout << q1.dequeue() << std::endl;

  std::cout << q1.getSize() << std::endl;
  std::cout << q1.isEmpty() << std::endl;
}