#include <bits/stdc++.h>
using namespace std;
int n, m, nb, d, minD, minDistance = INFINITY;
vector<pair<int, int>> chicken;
vector<pair<int, int>> home;
vector<int> selectedChicken;

int distance(pair<int, int> n1, pair<int, int> n2) {
  return abs(n1.first - n2.first) + abs(n1.second - n2.second);
}

void Solution() {
  // 치킨집이랑 집이랑 거리 비교해서 매칭 후 최소 거리 선택
  int chickenDistance = 0;
  for (auto h : home) {
    minD = 100;
    for (int i : selectedChicken) {
      d = distance(h, chicken[i]);
      minD = min(minD, distance(h, chicken[i]));
    }
    chickenDistance += minD;
  }
  minDistance = min(minDistance, chickenDistance);
  return;
}

void comb(int start) {
  if (selectedChicken.size() == m) {
    Solution();
    return;
  }
  for (int i = start + 1; i < chicken.size(); i++) {
    selectedChicken.push_back(i);
    comb(i);
    selectedChicken.pop_back();
  }
  return;
}

void Input() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> nb;
      if (nb == 1)
        home.push_back({i, j});
      else if (nb == 2)
        chicken.push_back({i, j});
    }
  }
}

void Solve() {
  Input();
  comb(-1);
  cout << minDistance << "\n";
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  Solve();

  return 0;
}