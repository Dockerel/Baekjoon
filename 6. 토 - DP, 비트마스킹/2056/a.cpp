#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 10004

using namespace std;

int n, ret;
int inDegree[MAX];
int processTime[MAX];
int dp[MAX];
vector<int> graph[MAX];

int t, num, node;

queue<int> q;

void init() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> t >> num;
    processTime[i] = t;
    inDegree[i] = num;
    for (int _ = 0; _ < num; _++) {
      cin >> node;
      graph[node].push_back(i);
    }
  }
}

void go() {
  for (int i = 1; i <= n; i++) {
    if (inDegree[i] == 0) {
      q.push(i);
      dp[i] = processTime[i];
    }
  }

  while (!q.empty()) {
    int curr = q.front();
    q.pop();

    ret = max(ret, dp[curr]);

    for (auto it : graph[curr]) {
      dp[it] = max(dp[it], dp[curr] + processTime[it]);
      if (--inDegree[it] == 0) {
        q.push(it);
      }
    }
  }

  cout << ret << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}