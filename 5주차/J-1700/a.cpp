#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, k, name;
vector<int> history;
queue<int> use[104];
int plug[104];
int ret;

void init() {
  cin >> n >> k;
  for (int i = 0; i < k; i++) {
    cin >> name;
    history.push_back(name);
    use[name].push(i);
  }
  memset(plug, -1, sizeof(plug));
  ret = 0;
}

int plugIsEmpty() {
  for (int i = 0; i < n; i++) {
    if (plug[i] == -1) return i;
  }
  return -1;
}

bool alreadyPlug(int num) {
  for (int i = 0; i < n; i++) {
    if (plug[i] == num) return true;
  }
  return false;
}

int findToUnplugNo() {
  // 1순위 : use에 없는 애
  for (int i = 0; i < n; i++) {
    if (use[plug[i]].empty()) return i;
  }

  // 2순위 : 제일 나중에 사용되는 애 찾기
  int whenPlug = -1;
  int plugNo;
  for (int i = 0; i < n; i++) {
    int nextTime = use[plug[i]].front();
    if (whenPlug < nextTime) {
      whenPlug = nextTime;
      plugNo = i;
    }
  }
  return plugNo;
}

void go() {
  for (auto it : history) {
    // 이미 꽂혀있는지 확인
    if (alreadyPlug(it)) {
      use[it].pop();
      continue;
    }

    // 비어 있는지 확인
    // 비어 있으면 거기 꽂기
    int emptyNo = plugIsEmpty();
    if (emptyNo >= 0) {
      plug[emptyNo] = it;
      use[it].pop();
      continue;
    }

    // 안비어 있으면 뺄 플러그 탐색(꽂혀 있는 애들 중에서)
    // 1순위 : use에 없는 애
    // 2순위 : 제일 나중에 사용되는 애
    int unplugNo = findToUnplugNo();
    plug[unplugNo] = it;
    use[it].pop();
    ret += 1;
  }
  cout << ret << "\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}