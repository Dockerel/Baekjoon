#include <bits/stdc++.h>
using namespace std;
int kth(vector<int>& a, int k) {
  random_device rd;
  shuffle(a.begin(), a.end(), default_random_engine(rd()));
  nth_element(a.begin(), a.begin() + k - 1, a.end());
  return a[k - 1];
}