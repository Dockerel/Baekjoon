#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, m, num;

vector<int> nums;

int prv[1000004];
int nxt[1000004];

int i, j;
string cmd;

void init() {
  cin >> n >> m;
  for (int _ = 0; _ < n; _++) {
    cin >> num;
    nums.push_back(num);
  }

  for (int i = 0; i < n; i++) {
    int currIdx = i;
    int prevIdx = i == 0 ? n - 1 : i - 1;
    int nextIdx = i == n - 1 ? 0 : i + 1;
    prv[nums[currIdx]] = nums[prevIdx];
    nxt[nums[currIdx]] = nums[nextIdx];
  }
}

void insert(int idx1, int idx2, int mid) {
  nxt[idx1] = j;
  prv[idx2] = j;
  prv[j] = idx1;
  nxt[j] = idx2;
}

void _delete(int idx1, int idx2, int mid) {
  nxt[idx1] = nxt[mid];
  prv[idx2] = prv[mid];
}

void go() {
  for (int _ = 0; _ < m; _++) {
    cin >> cmd;
    if (cmd == "BN") {
      cin >> i >> j;
      cout << nxt[i] << "\n";
      insert(i, nxt[i], j);
    } else if (cmd == "BP") {
      cin >> i >> j;
      cout << prv[i] << "\n";
      insert(prv[i], i, j);
    } else if (cmd == "CN") {
      cin >> i;
      cout << nxt[i] << "\n";
      _delete(i, nxt[nxt[i]], nxt[i]);
    } else {
      cin >> i;
      cout << prv[i] << "\n";
      _delete(prv[prv[i]], i, prv[i]);
    }
  }
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}