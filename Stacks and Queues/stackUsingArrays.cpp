#include <climits>
#include <iostream>
const int initalStackSize = 4;

template <class T> class Stack {
private:
  T *data;
  int nextIndex;
  int capacity;

public:
  // constructor
  Stack() {
    nextIndex = 0;
    data = new T[initalStackSize];
    capacity = initalStackSize;
  }

  // destructor
  ~Stack() { delete[] data; }

  // tells if stack is empty or not
  bool isEmpty() { return nextIndex == 0; }

  // return last index value
  T top() {
    if (!isEmpty())
      return data[nextIndex - 1];
    return 0;
  }

  // decrease index and return last index value
  T pop() {
    if (!isEmpty())
      return data[--nextIndex];
    return 0;
  }

  // append element to the end
  void push(int val) {
    // if stack if full double the size
    if (nextIndex == capacity) {
      // create new array and copy existing data
      T *newData = new T[2 * capacity];
      for (int i = 0; i < capacity; i++) {
        newData[i] = data[i];
      }
      // free up earlier array and let data point to new array
      delete[] data;
      data = newData;
      // double the capacity var
      capacity *= 2;
    }
    // add the element
    data[nextIndex] = val;
    nextIndex++;
  }
};

int main(void) {
  // example of int stack
  Stack<int> s1;
  s1.push(101);
  s1.push(102);
  s1.push(103);

  std::cout << s1.pop() << std::endl;
  std::cout << s1.pop() << std::endl;

  // example of char stack
  Stack<char> s2;
  s2.push('a');
  s2.push('b');
  std::cout << s2.pop() << std::endl;
  std::cout << s2.pop() << std::endl;

  return 0;
}