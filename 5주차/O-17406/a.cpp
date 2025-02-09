#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define tii tuple<int, int, int>

using namespace std;

int n, m, k;
int a[104][104];
int r, c, s;
vector<tii> spins;
vector<int> v;

int temp[104][104];

int ret = 5004;

void init() {
  cin >> n >> m >> k;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  for (int i = 0; i < k; i++) {
    cin >> r >> c >> s;
    spins.push_back({r - 1, c - 1, s});
    v.push_back(i);
  }
}

void spin_arr(int mid_y, int mid_x, int range) {
  if (range == 0) {
    return;
  }

  int _prev = -1;
  int curr_y = mid_y - range;
  int curr_x = mid_x - range;

  for (int i = curr_x; i <= curr_x + (range * 2); i++) {
    swap(_prev, temp[curr_y][i]);
  }
  curr_y += 1;
  curr_x += (range * 2);
  for (int i = curr_y; i < curr_y + (range * 2); i++) {
    swap(_prev, temp[i][curr_x]);
  }
  curr_y += ((range * 2) - 1);
  curr_x -= 1;
  for (int i = curr_x; i > curr_x - (range * 2); i--) {
    swap(_prev, temp[curr_y][i]);
  }
  curr_y -= 1;
  curr_x -= ((range * 2) - 1);
  for (int i = curr_y; i > curr_y - (range * 2); i--) {
    swap(_prev, temp[i][curr_x]);
  }

  spin_arr(mid_y, mid_x, range - 1);
}

void go() {
  do {
    // a에서 temp로 copy
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        temp[i][j] = a[i][j];
      }
    }

    // spin
    for (auto it : v) {
      tie(r, c, s) = spins[it];
      spin_arr(r, c, s);
    }

    // sum 계산 후 최솟값 업데이트
    for (int i = 0; i < n; i++) {
      ret = min(ret, accumulate(&temp[i][0], &temp[i][m], 0));
    }
  } while (next_permutation(v.begin(), v.end()));

  cout << ret << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}