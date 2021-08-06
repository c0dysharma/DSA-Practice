#include <iostream>

int lootHouseMaxCount(int n, int* val) {
  int arr[n];
  arr[0] = val[0];
  arr[1] = std::max(val[0], val[1]);

  for(int i =2; i<n; i++){
    arr[i] = std::max(val[i] + arr[i-2], arr[i-1]);
  }

  return arr[n-1];
}

int main(void) {
  int n;
  std::cin >> n;
  int arr[n];

  for(int i =0; i<n; i++){
    std::cin >> arr[i];
  }

  std::cout << lootHouseMaxCount(n, arr) << std::endl;
  return 0;
}

/*
Chapter Assignment
Problem Statement: Loot Houses
Problem Level: MEDIUM
Problem Description:
A thief wants to loot houses. He knows the amount of money in each house. He
cannot loot two consecutive houses. Find the maximum amount of money he can
loot. Input format : The first line of input contains an integer value of 'n'.
It is the total number of houses.

The second line of input contains 'n' integer values separated by a single space
denoting the amount of money each house has.

Output format :
Print the the maximum money that can be looted.

Constraints :
0 <= n <= 10 ^ 4

Time Limit: 1 sec

Sample Input 1 :
6
5 5 10 100 10 5

Sample Output 1 :
110

Sample Input 2 :
6
10 2 30 20 3 50

Sample Output 2 :
90

Explanation of Sample Output 2 :
Looting first, third, and the last houses([10 + 30 + 50]) will result in the
maximum loot, and all the other possible combinations would result in less
than 90.
*/