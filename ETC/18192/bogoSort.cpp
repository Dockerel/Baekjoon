#include "bogoSort.h"

#include <algorithm>

using namespace std;

bool check(vector<int> arr, vector<int> sorted_arr) {
  for (int i = 0; i < arr.size(); i++)
    if (arr[i] != sorted_arr[i]) return false;
  return true;
}

void sort_array(int N) {
  vector<int> arr = copy_array();
  vector<int> sorted_arr = arr;
  sort(sorted_arr.begin(), sorted_arr.end());

  int st = 0, ed = N - 1;
  while (!check(arr, sorted_arr)) {
    while (arr[st] != st) {
      for (int i = st; i < N; i++) {
        if (arr[i] == st) {
          ed = i;
          break;
        }
      }
      shuffle_array(st, ed);
      arr = copy_array();
    }
    st++;
  }
}