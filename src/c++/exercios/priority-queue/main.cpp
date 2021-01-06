#include <iostream>
#include <queue>

using namespace std;

// priority queue - fila de propiedades é usado em muitos algorimos
// Normalmente é uma fila de chave valor

// Quando usar ?
//

int main() {

  priority_queue<int> pq;

  pq.push(10);
  pq.push(30);
  pq.push(20);

  cout << pq.top() << endl;
}
