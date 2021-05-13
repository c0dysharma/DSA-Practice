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
  if(temp.size() != 0){
      return false;
  }else return true;
}

int main() {
  string exp;
  std::cin >> exp;
  stack<char> temp;
  cout << checkBrackets(exp, temp) << endl;
}