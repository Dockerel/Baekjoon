#include <bits/stdc++.h>
using namespace std;
vector<int> adj[10004];
int visited[10004];
int dfs(int here) {
  int ret = 1;
  for (int i : adj[here]) {
    if (visited[i]) continue;
    visited[i] = 1;
    ret += dfs(i);
  }
  return ret;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  adj[1].push_back(2);
  adj[1].push_back(3);
  visited[1] = 1;
  cout << dfs(1) << '\n';

  return 0;
}