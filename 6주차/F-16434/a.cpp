#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define ll long long
#define MAX 999999000001

using namespace std;

int n, hAtk;
int ti, ai, hi;
vector<tuple<int, int, int>> rooms;
ll status, attackPoint, hpPoint;

void init() {
  cin >> n >> hAtk;
  for (int _ = 0; _ < n; _++) {
    cin >> ti >> ai >> hi;
    rooms.push_back({ti, ai, hi});
  }
}

int fight(ll hp) {
  ll maxHp = hp;
  ll currHp = hp;
  ll currAtk = hAtk;

  for (auto it : rooms) {
    tie(status, attackPoint, hpPoint) = it;

    if (status == 1) {
      // 항상 몬스터를 때린 횟수보다 용사가 맞은 횟수가 1 작으므로
      ll cnt = hpPoint / currAtk;  // 어차피 1 빼야 하므로 그대로 쓰는데,
      if (hpPoint % currAtk == 0) cnt -= 1;  // 0 이면 1 한번 더 빼주기
      ll attackAmount = cnt * attackPoint;
      currHp -= attackAmount;
      if (currHp <= 0) {  // 용사 죽음
        return false;
      }
    } else {
      currAtk += attackPoint;
      currHp += hpPoint;
      currHp = min(currHp, maxHp);
    }
  }
  return true;
}

void go() {
  ll left = 1;
  ll right = MAX * n;
  ll ret = 0;

  while (left <= right) {
    ll mid = (left + right) / 2;
    if (fight(mid)) {
      ret = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
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