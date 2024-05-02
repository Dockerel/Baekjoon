#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 10004

using namespace std;

int v, e;
int n1, n2;
int t;
typedef struct {
  int num;
  int start;
  int finish;
} stat;
vector<int> graph[MAX];
vector<int> i_graph[MAX];
int visited[MAX];
vector<stat> _time;
vector<vector<int>> ret;
vector<int> temp;

bool cmp1(stat a, stat b) { return a.finish > b.finish; }
bool cmp2(vector<int> a, vector<int> b) { return a[0] < b[0]; }

void init() {
  cin >> v >> e;
  for (int i = 0; i < e; i++) {
    cin >> n1 >> n2;
    graph[n1].push_back(n2);
    i_graph[n2].push_back(n1);
  }
  t = 0;
  return;
}

void dfs(int node) {
  visited[node] = 1;
  stat temp;
  temp.num = node;
  temp.start = t++;
  for (int it : graph[node]) {
    if (!visited[it]) dfs(it);
  }
  temp.finish = t++;
  _time.push_back(temp);
  return;
}

void i_dfs(int node) {
  visited[node] = 1;
  for (int it : i_graph[node]) {
    if (!visited[it]) {
      temp.push_back(it);
      i_dfs(it);
    }
  }
  return;
}

void go() {
  // 1. dfs 돌리기
  memset(visited, 0, sizeof(visited));
  for (int i = 1; i <= v; i++) {
    if (!visited[i]) {
      dfs(i);
    }
  }

  // 2. _time sort
  sort(_time.begin(), _time.end(), cmp1);

  // 3. 뒤에서부터 i_dfs
  memset(visited, 0, sizeof(visited));
  for (auto it : _time) {
    if (!visited[it.num]) {
      temp.clear();
      temp.push_back(it.num);
      i_dfs(it.num);
      ret.push_back(temp);
    }
  }

  // 4. 결과 출력
  int len = ret.size();
  for (int i = 0; i < len; i++) {
    sort(ret[i].begin(), ret[i].end());
  }
  sort(ret.begin(), ret.end(), cmp2);
  cout << len << "\n";
  for (int i = 0; i < len; i++) {
    sort(ret[i].begin(), ret[i].end());
    for (auto it : ret[i]) cout << it << " ";
    cout << "-1\n";
  }

  return;
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}