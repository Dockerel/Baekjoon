#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pii pair<int, int>
#define ff first
#define ss second

using namespace std;

int n, w, x, y;
vector<pii> v;
int dp[1004][1004];

void init() {
  cin >> n;
  cin >> w;
  v.push_back({1, 1});
  v.push_back({n, n});
  for (int _ = 0; _ < w; _++) {
    cin >> x >> y;
    v.push_back({x, y});
  }
}

int dist(int a, int b) {
  return abs(v[a].ff - v[b].ff) + abs(v[a].ss - v[b].ss);
}

int go(int a, int b) {
  if (a == w + 1 || b == w + 1) return 0;
  if (dp[a][b]) return dp[a][b];
  int next = max(a, b) + 1;
  return dp[a][b] =
             min(go(a, next) + dist(b, next), go(next, b) + dist(a, next));
}

int main() {
  fastIO;
  init();
  cout << go(0, 1) << "\n";
  int a, b;
  a = 0, b = 1;
  for (int i = 2; i < w + 2; i++) {
    if (dp[a][i] + dist(b, i) < dp[i][b] + dist(a, i)) {
      cout << 2 << "\n";
      b = i;
    } else {
      cout << 1 << "\n";
      a = i;
    }
  }
  return 0;
}