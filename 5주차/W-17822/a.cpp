#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF -1

using namespace std;

// 원판을 아래와 같은 방법으로 총 T번 회전시키려고 한다. 원판의 회전 방법은 미리
// 정해져 있고, i번째 회전할때 사용하는 변수는 xi, di, ki이다.

// 번호가 xi의 배수인 원판을 di방향으로 ki칸 회전시킨다. di가 0인 경우는 시계
// 방향, 1인 경우는 반시계 방향이다. 원판에 수가 남아 있으면, 인접하면서 수가
// 같은 것을 모두 찾는다. 그러한 수가 있는 경우에는 원판에서 인접하면서 같은
// 수를 모두 지운다. 없는 경우에는 원판에 적힌 수의 평균을 구하고, 평균보다 큰
// 수에서 1을 빼고, 작은 수에는 1을 더한다.

int n, m, t, num, ret;
int xi, di, ki;

vector<vector<int>> plates;

int dy[4] = {1, 0, -1, 0};
int dx[4] = {0, 1, 0, -1};

void init() {
  cin >> n >> m >> t;
  plates.push_back({0});
  for (int i = 1; i <= n; i++) {
    vector<int> plate;
    for (int _ = 0; _ < m; _++) {
      cin >> num;
      plate.push_back(num);
    }
    plates.push_back(plate);
  }
  ret = 0;
}

void go() {
  for (int idx = 0; idx < t; idx++) {
    cin >> xi >> di >> ki;

    for (int i = xi; i <= n; i += xi) {
      if (di == 0) {
        // 시계 방향
        for (int r = 0; r < ki; r++)
          rotate(plates[i].begin(), plates[i].end() - 1, plates[i].end());
      } else {
        // 시계 반대 방향
        for (int r = 0; r < ki; r++)
          rotate(plates[i].begin(), plates[i].begin() + 1, plates[i].end());
      }
    }

    int nums = 0;
    // 2-1. 있으면 인접하면서 같은 수 모두 제거
    int visited[54][54];
    queue<pair<int, int>> q;
    int y, x;

    memset(visited, 0, sizeof(visited));
    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < m; j++) {
        if (visited[i][j] == 0 && plates[i][j] != INF) {
          int tempNum = 0;
          visited[i][j] = 1;
          q.push({i, j});

          while (!q.empty()) {
            tie(y, x) = q.front();
            q.pop();
            for (int k = 0; k < 4; k++) {
              int ny = y + dy[k];
              int nx = x + dx[k];

              nx = (nx < 0 ? m - 1 : nx % m);
              if (ny == 0 || ny > n || visited[ny][nx] ||
                  plates[i][j] != plates[ny][nx])
                continue;
              q.push({ny, nx});
              tempNum = nums = 1;
              visited[ny][nx] = 1;
              plates[ny][nx] = INF;
            }
          }
          if (tempNum) plates[i][j] = INF;
        }
      }
    }

    // 2-2. 없으면 해당 판 평균 구해서 그거보다 크면 -1, 작으면 +1
    if (nums == 0) {
      double avg = 0;
      int allN = 0;
      for (int i = 1; i <= n; i++) {
        for (auto it : plates[i]) {
          if (it != INF) {
            avg += it;
            allN += 1;
          }
        }
      }
      if (allN == 0)
        avg = 0;
      else
        avg /= allN;  // 평균
      for (int i = 1; i <= n; i++) {
        vector<int> newV;
        for (auto it : plates[i]) {
          if (it == INF) {
            newV.push_back(it);
            continue;
          }
          if (avg < it) {
            newV.push_back(it - 1);
          } else if (avg > it) {
            newV.push_back(it + 1);
          } else {
            newV.push_back(it);
          }
        }
        plates[i] = newV;
      }
    }
  }

  // 원판을 T번 회전시킨 후 원판에 적힌 수의 합을 출력
  for (int i = 1; i <= n; i++) {
    auto plate = plates[i];
    for (auto it : plate) {
      if (it != INF) ret += it;
    }
  }
  cout << ret << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}