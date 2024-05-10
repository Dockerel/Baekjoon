#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 104
#define pii pair<int, int>

using namespace std;

int n, tm;
int costs[MAX], visited[MAX];
string s;
vector<int> graph[MAX], r_graph[MAX];
vector<pair<int, pii>> times;

bool cmp(pii a, pii b) { return a.second > b.second; }

void init() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> costs[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> s;
    for (int j = 0; j < n; j++) {
      if (s[j] == '1') {
        graph[i].push_back(j);
        graph[j].push_back(i);
      }
    }
  }
  tm = 0;
  return;
}

void dfs(int here) {
  visited[here] = 1;
  pair<int, pii> temp;
  temp.first = here;
  temp.second.first = tm++;
  for (auto it : graph[here]) {
    if (!visited[it]) {
      dfs(it);
    }
  }
  temp.second.second = tm++;
  times.push_back(temp);
}

void r_dfs(int here) {}

void go() {
  // 정방향 dfs
  memset(visited, 0, sizeof(visited));
  for (int i = 0; i < n; i++) {
    if (!visited[i]) {
      dfs(i);
    }
  }
  // finish time 기준 내림차순 정렬
  sort(times.begin(), times.end(), cmp);
  // 역방향 dfs하면서 끊기
  memset(visited, 0, sizeof(visited));
  for (auto it : times) {
    if (!visited[it.first]) {
      r_dfs(it.first);
    }
  }
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}