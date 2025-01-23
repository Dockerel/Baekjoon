#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int N, L;
int a[104][104];
vector<int> road;
int curr;
int visited[104];
int ret;

int debug_num = 1;

void init() {
  cin >> N >> L;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      cin >> a[i][j];
    }
  }
  ret = 0;
}

void verifyRoad() {
  curr = 0;
  memset(visited, 0, sizeof(visited));  // 0: 경사로 없음, 1: 경사로 있음

  while (curr < N - 1) {
    if (road[curr] == road[curr + 1]) {
      curr += 1;
    } else {
      // 경사로 놓을 수 있는지
      // 1. 오르막길
      if (road[curr] < road[curr + 1]) {
        // curr부터 L개 뒤로 확인
        if (road[curr + 1] - road[curr] != 1) return;
        for (int i = curr; i > curr - L; i--) {
          if (i < 0 || visited[i] || road[i] != road[curr])
            return;
          else
            visited[i] = 1;
        }
        curr += 1;
      }
      // 2. 내리막길
      else {
        // curr부터 L개 앞으로 확인
        if (road[curr] - road[curr + 1] != 1) return;
        for (int i = curr + 1; i <= curr + L; i++) {
          if (i > N - 1 || visited[i] || road[i] != road[curr] - 1)
            return;
          else
            visited[i] = 1;
        }
        curr += L;
      }
    }
  }
  ret += 1;
}

void go() {
  road.clear();

  // 가로
  for (int i = 0; i < N; i++) {
    road.clear();
    for (int j = 0; j < N; j++) {
      road.push_back(a[i][j]);
    }
    verifyRoad();
  }

  // 세로
  for (int i = 0; i < N; i++) {
    road.clear();
    for (int j = 0; j < N; j++) {
      road.push_back(a[j][i]);
    }
    verifyRoad();
  }

  cout << ret << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}