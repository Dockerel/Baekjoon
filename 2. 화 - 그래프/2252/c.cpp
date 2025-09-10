#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 32004

using namespace std;

int n, m, n1, n2;
vector<int> graph[MAX];
int visited[MAX];
int _time;
typedef struct {
  int start;
  int finish;
  int num;
} node;
vector<node> _times;

void init() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    cin >> n1 >> n2;
    graph[n1].push_back(n2);
  }
  memset(visited, 0, sizeof(visited));
  _time = 0;
  return;
}

void go(int here) {
  node temp;
  temp.start = _time++;
  temp.num = here;
  visited[here] = 1;
  for (int it : graph[here]) {
    if (!visited[it]) {
      go(it);
    }
  }
  temp.finish = _time++;
  _times.push_back(temp);
  return;
}

bool cmp(node a, node b) { return a.finish > b.finish; }

int main() {
  fastIO;
  init();

  for (int i = 1; i <= n; i++) {
    if (!visited[i]) go(i);
  }
  sort(_times.begin(), _times.end(), cmp);
  for (auto it : _times) {
    cout << it.num << " ";
  }
  cout << "\n";

  return 0;
}