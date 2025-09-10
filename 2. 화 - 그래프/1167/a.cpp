#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ppl pair<int, int>

using namespace std;

int n;
vector<ppl> tree[100004];
int p, n1, n2;
int visited[100004];

void init() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> p;
    while (true) {
      cin >> n1;
      if (n1 == -1) break;
      cin >> n2;
      tree[p].push_back({n1, n2});
    }
  }
}

ppl calRadius(int node) {
  queue<ppl> q;

  int maxNode = 0;
  int maxRadius = -1;

  memset(visited, 0, sizeof(visited));
  visited[node] = 1;

  for (auto it : tree[node]) {
    q.push(it);
    while (!q.empty()) {
      ppl temp = q.front();
      q.pop();
      if (tree[temp.first].size() == 1) {
        if (temp.second > maxRadius) {
          maxRadius = temp.second;
          maxNode = temp.first;
        }
        continue;
      }
      for (auto it1 : tree[temp.first]) {
        if (visited[it1.first] == 0) {
          visited[it1.first] = 1;
          q.push({it1.first, temp.second + it1.second});
        }
      }
    }
  }

  return {maxNode, maxRadius};
}

void go() {
  ppl temp1 = calRadius(1);
  ppl ret = calRadius(temp1.first);
  cout << ret.second << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}