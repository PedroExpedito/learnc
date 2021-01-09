// stack lifo

#include <iostream>
#include <stack>

using namespace std;
int main() {

  stack<int> s;

  s.push(10);
  s.push(40);
  s.push(20);

  while(!s.empty()) {
    cout << s.top() << endl;
    s.pop();
  }
  cout << sizeof(bool) << endl;
  cout << sizeof(char) << endl;
}
