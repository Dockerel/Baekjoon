#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n, m;
vector<int> words;
string s;

void init() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> s;
    int word = 0;
    for (char c : s) {
      word |= (1 << (c - 'a'));
    }
    words.push_back(word);
  }
}

int count(int mask) {
  int cnt = 0;
  for (int word : words) {
    if (word && (word & mask) == word) cnt++;
  }
  return cnt;
}

int go(int idx, int k, int mask) {
  if (k < 0) return 0;
  if (idx == 26) return count(mask);
  int ret = go(idx + 1, k - 1, mask | (1 << idx));
  if (idx != 'a' - 'a' && idx != 'n' - 'a' && idx != 't' - 'a' &&
      idx != 'i' - 'a' && idx != 'c' - 'a') {
    ret = max(ret, go(idx + 1, k, mask));
  }
  return ret;
}

int main() {
  fastIO;
  init();
  cout << go(0, m, 0) << "\n";
  return 0;
}