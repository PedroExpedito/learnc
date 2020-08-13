#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  int a1 = 2, a2 = 2, a3 = 2;
  int contador = 0;
  cin >> n;
  for (int i = 0; i < n; i++) {
    a3 = a2;
    a2 = a1;
    cin >> a1;
    if (a3 == 1 && a2 == 0 && a1 == 0)
      contador++;
  }
  cout << contador;
  exit(0);
}
