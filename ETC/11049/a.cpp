#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 2147483647
#define MAX 504
#define pii pair<int, int>
#define ff first
#define ss second

using namespace std;

int n, r, c;
vector<pii> mats;

int dp[MAX][MAX];
pii rcDp[MAX][MAX];

void init() {
  cin >> n;
  mats.push_back({0, 0});
  for (int i = 0; i < n; i++) {
    cin >> r >> c;
    mats.push_back({r, c});
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dp[i][j] = INF;
    }
  }
}

int go(int from, int to) {
  int &temp = dp[from][to];
  if (temp != INF) {
    return temp;
  }

  if (from >= to) {
    rcDp[to][to] = mats[to];
    return 0;
  }

  if (to - from == 1) {
    temp = min(temp, mats[from].ff * mats[from].ss * mats[to].ss);
    rcDp[from][to] = {mats[from].ff, mats[to].ss};
    return temp;
  }

  for (int i = from; i <= to; i++) {
    temp =
        min(temp, go(from, i) + go(i + 1, to) +
                      rcDp[from][i].ff * rcDp[from][i].ss * rcDp[i + 1][to].ss);
  }
  rcDp[from][to] = {mats[from].ff, mats[to].ss};
  return temp;
}

int main() {
  fastIO;
  init();
  cout << go(1, n) << "\n";
  return 0;
}

// 5 3 | 3 2 | 2 6 | 6 3