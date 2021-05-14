#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool checkBrackets(string exp, stack<char> temp) {
  for (auto c : exp) {
    if (c == '(' || c == '{' || c == '[')
      temp.push(c);
    else if (c == ')' || c == '}' || c == ']') {
      if (c == ')') {
        if (temp.top() == '(') {
          temp.pop();
          continue;
        } else
          return false;
      }
      if (c == '}') {
        if (temp.top() == '{') {
          temp.pop();
          continue;
        } else
          return false;
      }
      if (c == ']') {
        if (temp.top() == '[') {
          temp.pop();
          continue;
        } else
          return false;
      }
    } else
      continue;
  }
  if (temp.size() != 0) {
    return false;
  } else
    return true;
}

void reverseStack(stack<int> &s1, stack<int> s2) {
  // base case
  int len = s1.size();
  if (len == 0 || len == 1)
    return;

  int topVal = s1.top();
  s1.pop();
  // recursive call
  reverseStack(s1, s2);
  // smaller calculation
  // copy existing element into s2
  while (!s1.empty()) {
    s2.push(s1.top());
    s1.pop();
  }
  // add first element to last and copy back other vals
  s1.push(topVal);
  while (!s2.empty()) {
    s1.push(s2.top());
    s2.pop();
  }
}

int main() {
  // string exp;
  // std::cin >> exp;
  // stack<char> temp;
  // cout << checkBrackets(exp, temp) << endl;
  stack<int> s1;
  s1.push(10);
  s1.push(20);
  s1.push(30);
  stack<int> s2;

  reverseStack(s1, s2);
  while (!s1.empty()) {
    cout << s1.top() << " ";
    s1.pop();
  }
  cout << endl;
}