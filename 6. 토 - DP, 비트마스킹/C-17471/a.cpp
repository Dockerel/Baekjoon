#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321

using namespace std;

int n, adjN, num;
int humanCnt[12];
vector<int> graph[12];

vector<int> area0, area1;
int humanDiff;
int ret;
int visited[12];
queue<int> q;

void init() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> humanCnt[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> adjN;
    for (int _ = 0; _ < adjN; _++) {
      cin >> num;
      graph[i].push_back(num);
    }
  }
  ret = INF;
}

int bfs(int areaType, int start) {
  // start가 0일때는 visited에 area1인 애들 다 추가
  // start가 1일때는 visited에 area0인 애들 다 추가
  memset(visited, 0, sizeof(visited));
  for (auto it : (areaType == 0 ? area1 : area0)) {
    visited[it] = 1;
  }

  while (!q.empty()) q.pop();

  q.push(start);
  visited[start] = 1;
  while (!q.empty()) {
    int curr = q.front();
    q.pop();
    for (auto it : graph[curr]) {
      if (!visited[it]) {
        q.push(it);
        visited[it] = 1;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    if (!visited[i]) return 0;
  }
  return 1;
}

void go() {
  // 각 구역에 대해 경우의 수 모두 확인
  // dfs나 bfs로 인접 확인
  // 모든 구역이 인접하면 인구 차이 저장
  // 아니면 패스

  for (int i = 0; i < (1 << n); i++) {
    area0.clear();
    area1.clear();

    humanDiff = 0;

    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        area1.push_back(j + 1);
        humanDiff += humanCnt[j + 1];
      } else {
        area0.push_back(j + 1);
        humanDiff -= humanCnt[j + 1];
      }
    }
    humanDiff = abs(humanDiff);

    if (!area0.size() || !area1.size()) {
      continue;
    }

    if (bfs(0, area0[0]) && bfs(1, area1[0])) ret = min(ret, humanDiff);
  }

  cout << (ret == INF ? -1 : ret) << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}