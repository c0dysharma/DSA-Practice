#include "pq.h"
#include <iostream>

int main() {
  PriorityQueue pq;
  pq.insert(100);
  pq.insert(10);
  pq.insert(15);
  pq.insert(4);
  pq.insert(17);
  pq.insert(21);
  pq.insert(67);

  std::cout << pq.getSize() << std::endl;
  std::cout << pq.getMin() << std::endl;

  while(!pq.isEmpty()){
    std::cout << pq.removeMin() << ' ';
  }std::cout << std::endl;
  
  return 0;
}