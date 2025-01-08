#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, d, t, ret;
int schedule[100004][2];
int normal_t, additional_t;
vector<pair<int, int>> works;

void init() {
  cin >> n;
  for (int _ = 0; _ < n; _++) {
    cin >> d >> t;
    works.push_back({d, t});
  }
  normal_t = additional_t = 1;
  memset(schedule, 0, sizeof(schedule));
  ret = 0;
}

bool cmp(pair<int, int> a, pair<int, int> b) { return a.first < b.first; }

void go() {
  sort(works.begin(), works.end(), cmp);

  for (auto work : works) {
    int _time = work.second;
    int due_date = work.first;

    // 정규 시간대에 다 박아넣기
    for (int i = normal_t; i <= due_date; i += ((i + 2) % 7 == 0 ? 3 : 1)) {
      if (schedule[i][0] == 0) {
        schedule[i][0] = 1;
        _time--;
        normal_t += ((normal_t + 2) % 7 == 0 ? 3 : 1);
      }
      if (_time == 0) break;
    }

    // 추가 시간대에 다 박아넣기
    for (int i = additional_t; i <= due_date; i++) {
      if (_time == 0) break;
      if (schedule[i][1] == 0) {
        schedule[i][1] = 1;
        _time--;
        additional_t++;
        ret++;
      }
    }

    // 다 됐으면 다음꺼, 남았으면 실패 -> -1
    if (_time > 0) {
      cout << "-1\n";
      exit(0);
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