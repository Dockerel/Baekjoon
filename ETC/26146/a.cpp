#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 200004
#define pii pair<int, int>
#define pipii pair<int, pii>

using namespace std;

int n, m, from, to, currTm, ret;
vector<int> graph[MAX];
vector<int> r_graph[MAX];
pipii _time[MAX];
int visited[MAX];

bool cmp(pipii a, pipii b) { return a.second.second > b.second.second; }

void init() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> from >> to;
    graph[from].push_back(to);
    r_graph[to].push_back(from);
  }
  memset(visited, 0, sizeof(visited));
  currTm = 0;
  ret = 0;
}

void dfs(int here) {
  visited[here] = 1;
  pipii temp;
  temp.first = here;
  temp.second.first = currTm++;
  for (int it : graph[here]) {
    if (!visited[it]) {
      dfs(it);
    }
  }
  temp.second.second = currTm++;
  _time[here] = temp;
}

void r_dfs(int here) {
  visited[here] = 1;
  for (int it : r_graph[here]) {
    if (!visited[it]) {
      r_dfs(it);
    }
  }
}

void go() {
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      dfs(i);
    }
  }

  sort(_time + 1, _time + n + 1, cmp);

  memset(visited, 0, sizeof(visited));
  for (int i = 1; i <= n; i++) {
    pipii it = _time[i];
    if (!visited[it.first]) {
      r_dfs(it.first);
      ret++;
    }
    if (ret > 1) {
      cout << "No\n";
      exit(0);
    }
  }
  cout << "Yes\n";
}

int main() {
  fastIO;

  init();
  go();

  return 0;
}