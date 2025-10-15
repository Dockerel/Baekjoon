#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define MAX 10004

using namespace std;

int n, m, k;
int a[MAX];
int v, w;
vector<int> friends[MAX];
int visited[MAX];

void init() {
  cin >> n >> m >> k;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m; i++) {
    cin >> v >> w;
    friends[v].push_back(w);
    friends[w].push_back(v);
  }
}

void go() {
  // 그룹별로 나눠서 최저인 학생 선택 후 친구비의 합이 k 이하인지 확인
  int ret = 0;
  for (int i = 1; i <= n; i++) {
    if (visited[i] == 0) {
      int min_friend_fee = a[i];
      queue<int> q;
      q.push(i);
      while (!q.empty()) {
        int curr = q.front();
        q.pop();
        for (auto it : friends[curr]) {
          if (visited[it] == 0) {
            min_friend_fee = min(min_friend_fee, a[it]);
            visited[it] = 1;
            q.push(it);
          }
        }
      }
      ret += min_friend_fee;
    }
  }
  if (ret > k) {
    cout << "Oh no\n";
  } else {
    cout << ret << "\n";
  }
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}