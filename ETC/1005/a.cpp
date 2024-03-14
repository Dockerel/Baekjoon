#include <bits/stdc++.h>
using namespace std;
#define MAX 1004

int t, n, k, x, y, w;
int d[MAX];
int pre[MAX];
int ret[MAX];
vector<int> adj[MAX];

void Initialize() {
  fill(d, d + MAX, 0);
  fill(pre, pre + MAX, 0);
  fill(ret, ret + MAX, 0);
  for (int i = 1; i <= MAX; i++) adj[i].clear();
  return;
}

void Input() {
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> d[i];
  for (int i = 0; i < k; i++) {
    cin >> x >> y;
    adj[x].push_back(y);
    pre[y]++;
  }
  cin >> w;
  return;
}

void Solution() {
  queue<int> Q;

  for (int i = 1; i <= n; i++) {
    if (pre[i] == 0) {
      Q.push(i);
      ret[i] = d[i];
    }
  }

  while (!Q.empty()) {
    int cur = Q.front();
    Q.pop();

    for (int next : adj[cur]) {
      ret[next] = max(ret[next], ret[cur] + d[next]);
      pre[next]--;

      if (pre[next] == 0) Q.push(next);
    }
  }

  cout << ret[w] << "\n";
  return;
}

void Solve() {
  Initialize();
  Input();
  Solution();
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> t;

  for (int i = 0; i < t; i++) {
    Solve();
  }

  return 0;
}