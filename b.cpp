#include <iostream>
#include <string>

using namespace std;

int main() {
  int n, m;
  string pok[100000];
  string q[100000];

  cin >> n >> m;

  for (int i = 0; i < n; i++) {
    cin >> pok[i];
  }

  for (int i = 0; i < m; i++) {
    cin >> q[i];
  }

  for (int i = 0; i < m; i++) {
    bool num = true;
    int index = 0;

    for (int j = 0; j < n; j++) {
      if (pok[j] == q[i]) {
        index = j + 1;
        num = false;
      }
    }

    if (num == true) {
      int find = stoi(q[i]);
      cout << pok[find - 1] << "\n";
    } else {
      cout << index << "\n";
    }
  }

  printf("end");
}