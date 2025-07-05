#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, m, k, ret;
vector<int> tree[10][10];
int a[10][10];
int nutrient[10][10];
int x, y, z;

int dy[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dx[8] = {0, 1, 1, 1, 0, -1, -1, -1};

void init() {
  cin >> n >> m >> k;

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
      nutrient[i][j] = 5;
    }
  }

  for (int _ = 0; _ < m; _++) {
    cin >> x >> y >> z;
    tree[x - 1][y - 1].push_back(z);
  }
}

void go() {
  for (int _ = 0; _ < k; _++) {
    // 봄
    // 봄에는 나무가 자신의 나이만큼 양분을 먹고, 나이가 1 증가한다. 각각의
    // 나무는 나무가 있는 1×1 크기의 칸에 있는 양분만 먹을 수 있다. 하나의 칸에
    // 여러 개의 나무가 있다면, 나이가 어린 나무부터 양분을 먹는다. 만약, 땅에
    // 양분이 부족해 자신의 나이만큼 양분을 먹을 수 없는 나무는 양분을 먹지
    // 못하고 즉시 죽는다.
    // 여름
    // 여름에는 봄에 죽은 나무가 양분으로 변하게 된다. 각각의 죽은 나무마다
    // 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로 추가된다. 소수점 아래는
    // 버린다.
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        int dead = 0;
        sort(tree[i][j].begin(), tree[i][j].end());
        vector<int> newTree;
        for (auto tr : tree[i][j]) {
          if (tr <= nutrient[i][j]) {
            nutrient[i][j] -= tr;
            newTree.push_back(tr + 1);
          } else {
            dead += (tr / 2);
          }
        }
        nutrient[i][j] += dead;
        tree[i][j] = newTree;
      }
    }

    // 가을
    // 가을에는 나무가 번식한다. 번식하는 나무는 나이가 5의 배수이어야 하며,
    // 인접한 8개의 칸에 나이가 1인 나무가 생긴다. 어떤 칸 (r, c)와 인접한 칸은
    // (r-1, c-1), (r-1, c), (r-1, c+1), (r, c-1), (r, c+1), (r+1, c-1), (r+1,
    // c), (r+1, c+1) 이다. 상도의 땅을 벗어나는 칸에는 나무가 생기지 않는다.
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        for (auto tr : tree[i][j]) {
          if (tr % 5) continue;
          for (int l = 0; l < 8; l++) {
            int ny = i + dy[l];
            int nx = j + dx[l];
            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            tree[ny][nx].push_back(1);
          }
        }
      }
    }

    // 겨울
    // 겨울에는 S2D2가 땅을 돌아다니면서 땅에 양분을 추가한다. 각 칸에 추가되는
    // 양분의 양은 A[r][c]이고, 입력으로 주어진다.
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; j++) {
        nutrient[i][j] += a[i][j];
      }
    }
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      ret += tree[i][j].size();
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