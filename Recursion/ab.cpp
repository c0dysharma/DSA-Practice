/*
Chapter Assignment
Problem Statement: Check AB
Problem Level: MEDIUM
Problem Description:
Suppose you have a string, S, made up of only 'a's and 'b's. Write a recursive function that checks if the string was generated using the following rules:
a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'

If all the rules are followed by the given string, return true otherwise return false.
Input format :
String S

Output format :
'true' or 'false'

Constraints :
0 <= |S| <= 1000
where |S| represents length of string S.

Sample Input 1 :
abb

Sample Output 1 :
true

Sample Input 2 :
abababa

Sample Output 2 :
false
*/
#include <bits/stdc++.h>
using namespace std;

bool check(string s, int i, int n, int count){
    if (i == n){                   // at the end of string
        if (count == 1) // the last element was single b its wrong
            return false;
        return true; // if we had 2 bb in the end its ok
    }

    if (s[i] == 'a') // if the element we have is a
    {
        if (count == 1) // means we had single b before this a which is wrong
            return false;
        count = 0; // if not means  we had 2 bs now we can check for next part
        return check(s, i + 1, n, count);
    }

    count++;       // increment if we encounter a b
    if (count > 2) // means we have more than 2 bs which is wrong we must have only 2 bs
        return false;
    return check(s, i + 1, n, count);
}

int main(){
    string s;
    cin >> s;
    cout << boolalpha << check(s,0,s.size(),0) << endl;
    return 0;
}