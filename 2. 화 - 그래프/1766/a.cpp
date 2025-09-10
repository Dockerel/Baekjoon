#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 32004

using namespace std;
int n, m, n1, n2;
int ins[MAX];
vector<int> graph[MAX];
priority_queue<int, vector<int>, greater<int> > pq;

void init() {
  memset(ins, 0, sizeof(ins));
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> n1 >> n2;
    graph[n1].push_back(n2);
    ins[n2]++;
  }
  for (int i = 1; i <= n; i++) {
    if (!ins[i]) {
      pq.push(i);
    }
  }
  return;
}

void go() {
  while (!pq.empty()) {
    int _min = pq.top();
    pq.pop();
    cout << _min << " ";
    for (auto it : graph[_min]) {
      if (--ins[it] == 0) {
        pq.push(it);
      }
    }
  }
  return;
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}