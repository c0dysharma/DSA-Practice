#include <iostream>
#include <queue>
using namespace std;

void reverseQueue(queue<int> &q){
    // base case
    int len = q.size();
    if(len == 0)
        return;

    // recursive call
    int topVal = q.front();
    q.pop();
    reverseQueue(q);

    // smaller calculation
   q.push(topVal);
}

int main(){
    queue<int> q1;
    q1.push(10);
    q1.push(20);
    q1.push(30);

    reverseQueue(q1);

    while(!q1.empty()){
        cout << q1.front() << " ";
        q1.pop();
    }cout << endl;
}