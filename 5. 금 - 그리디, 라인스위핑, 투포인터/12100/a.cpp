#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n;
int a[21][21], temp[21][21], temp2[21][21];
int ret;

vector<int> not0, moved;

void init() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  if (n == 1) {
    cout << a[0][0] << "\n";
    exit(0);
  }
  ret = -1;
}

void rotateTemp(int num) {
  for (int _ = 0; _ < num; _++) {
    // rorate temp

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        temp2[i][j] = temp[n - j - 1][i];
      }
    }

    memmove(temp, temp2, sizeof(temp));
  }
}

void moveup() {
  for (int i = 0; i < n; i++) {
    not0.clear();
    moved.clear();

    // 0 아닌거 걸러내기
    for (int j = 0; j < n; j++) {
      if (temp[j][i] > 0) not0.push_back(temp[j][i]);
    }

    // 합치는 작업
    for (int j = 0; j < not0.size(); j++) {
      if (j + 1 < not0.size()) {  // 뒤에꺼 있으면
        if (not0[j] == not0[j + 1]) {
          moved.push_back(not0[j] * 2);
          j += 1;
        } else {
          moved.push_back(not0[j]);
        }
        continue;
      }
      moved.push_back(not0[j]);
    }

    // temp 배열에 이식
    for (int j = 0; j < n; j++) {
      temp[j][i] = (j < moved.size() ? moved[j] : 0);
    }
  }
}

void movedown() {
  rotateTemp(2);
  moveup();
  rotateTemp(2);
}

void moveleft() {
  rotateTemp(1);
  moveup();
  rotateTemp(3);
}

void moveright() {
  rotateTemp(3);
  moveup();
  rotateTemp(1);
}

void go(string curr, int cnt) {
  if (cnt == 5) {
    // 움직이고 max 구하기

    for (int i = 0; i < n; i++)
      for (int j = 0; j < n; j++) temp[i][j] = a[i][j];

    for (char c : curr) {
      switch (c) {
        case '0':
          moveup();
          break;
        case '1':
          movedown();
          break;
        case '2':
          moveleft();
          break;
        case '3':
          moveright();
          break;
        default:
          break;
      }
    }

    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        ret = max(ret, temp[i][j]);
      }
    }

    return;
  }

  go(curr + '0', cnt + 1);  // 상
  go(curr + '1', cnt + 1);  // 하
  go(curr + '2', cnt + 1);  // 좌
  go(curr + '3', cnt + 1);  // 우
}

int main() {
  fastIO;
  init();
  go("", 0);
  cout << ret << "\n";
  return 0;
}