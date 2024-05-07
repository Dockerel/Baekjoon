#include <iostream>
#include <queue>
#include <stack>
#include <vector>

const int INF = 987654321;

using namespace std;

int n, m, s, d;
vector<pair<int, int>> g[1001];
priority_queue<pair<int, int>> pq;
int dist[1001], route[1001];
stack<int> st;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin >> n;
  cin >> m;

  int A, B, C;
  for (int i = 0; i < m; i++) {
    cin >> A >> B >> C;
    g[A].push_back({B, C});
  }

  for (int i = 1; i <= n; i++) {
    dist[i] = INF;
  }
  cin >> s >> d;

  dist[s] = 0;
  pq.push({s, 0});
  route[s] = 0;

  while (!pq.empty()) {
    int cnode = pq.top().first;
    int cdist = -pq.top().second;
    pq.pop();

    if (dist[cnode] < cdist) continue;

    for (int i = 0; i < g[cnode].size(); i++) {
      int nnode = g[cnode][i].first;
      int ndist = cdist + g[cnode][i].second;

      if (ndist < dist[nnode]) {
        route[nnode] = cnode;
        dist[nnode] = ndist;
        pq.push({nnode, -ndist});
      }
    }
  }

  cout << dist[d] << "\n";
  int cur = d;
  while (cur) {
    st.push(cur);
    cur = route[cur];
  }
  cout << st.size() << "\n";
  while (!st.empty()) {
    cout << st.top() << " ";
    st.pop();
  }
  cout << "\n";

  return 0;
}