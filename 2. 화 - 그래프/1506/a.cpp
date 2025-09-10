#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 104
using namespace std;

typedef pair<int, int> pii;

int n, _tm, min_cost;
int costs[MAX], visited[MAX];
string s;
vector<int> graph[MAX], r_graph[MAX];
vector<pair<int, pii>> times;
long long ret;

bool cmp(pair<int, pii> a, pair<int, pii> b) {
  return a.second.second > b.second.second;
}

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
        r_graph[j].push_back(i);
      }
    }
  }
  _tm = 0;
  return;
}

void dfs(int here) {
  visited[here] = 1;
  pair<int, pii> temp;
  temp.first = here;
  temp.second.first = _tm++;
  for (auto it : graph[here]) {
    if (!visited[it]) {
      dfs(it);
    }
  }
  temp.second.second = _tm++;
  times.push_back(temp);
}

void r_dfs(int here) {
  visited[here] = 1;
  min_cost = min(min_cost, costs[here]);
  for (auto it : r_graph[here]) {
    if (!visited[it]) {
      r_dfs(it);
    }
  }
}

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
      min_cost = 1000004;
      r_dfs(it.first);
      ret += min_cost;
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