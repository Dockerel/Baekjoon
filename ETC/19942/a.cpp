#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 987654321

using namespace std;

int n, _sum, temp_sum;
vector<int> ret, temp_ret;
tuple<int, int, int, int> _min, temp_min;
vector<tuple<int, int, int, int, int>> a;

void init() {
  cin >> n;
  cin >> get<0>(_min) >> get<1>(_min) >> get<2>(_min) >> get<3>(_min);
  for (int i = 0; i < n; i++) {
    tuple<int, int, int, int, int> temp;
    cin >> get<0>(temp) >> get<1>(temp) >> get<2>(temp) >> get<3>(temp) >>
        get<4>(temp);
    a.push_back(temp);
  }
  _sum = INF;
}

void go(int here) {
  if (here == n) {
    if (get<0>(_min) <= get<0>(temp_min) && get<1>(_min) <= get<1>(temp_min) &&
        get<2>(_min) <= get<2>(temp_min) && get<3>(_min) <= get<3>(temp_min)) {
      if (temp_sum < _sum) {
        ret = temp_ret;
        _sum = temp_sum;
      }
    }
    return;
  }

  if (get<0>(_min) <= get<0>(temp_min) && get<1>(_min) <= get<1>(temp_min) &&
      get<2>(_min) <= get<2>(temp_min) && get<3>(_min) <= get<3>(temp_min)) {
    if (temp_sum < _sum) {
      ret = temp_ret;
      _sum = temp_sum;
    }
    return;
  }

  temp_sum += get<4>(a[here]);
  get<0>(temp_min) += get<0>(a[here]);
  get<1>(temp_min) += get<1>(a[here]);
  get<2>(temp_min) += get<2>(a[here]);
  get<3>(temp_min) += get<3>(a[here]);
  temp_ret.push_back(here);
  go(here + 1);

  temp_sum -= get<4>(a[here]);
  get<0>(temp_min) -= get<0>(a[here]);
  get<1>(temp_min) -= get<1>(a[here]);
  get<2>(temp_min) -= get<2>(a[here]);
  get<3>(temp_min) -= get<3>(a[here]);
  temp_ret.pop_back();
  go(here + 1);
}

int main() {
  fastIO;
  init();


  go(0);

  if(_sum==INF)cout<<"-1\n";
  else{


  cout << _sum << "\n";
  for (auto it : ret) {
    cout << it+1 << " ";
  }
  cout << "\n";
  }

  return 0;
}