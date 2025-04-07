#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define vi vector<int>

using namespace std;

vector<vi> graph;
vector<int> scores;
int dices[10];
int ret;

void init() {
  graph = {{1},  {2},      {3},  {4},  {5},  {6, 22}, {7},      {8},  {9},
           {10}, {11, 26}, {12}, {13}, {14}, {15},    {16, 28}, {17}, {18},
           {19}, {20},     {21}, {21}, {23}, {24},    {25},     {31}, {27},
           {25}, {29},     {30}, {25}, {32}, {20}};
  scores = {0,  2,  4,  6,  8, 10, 12, 14, 16, 18, 20, 22, 24, 26, 28, 30, 32,
            34, 36, 38, 40, 0, 13, 16, 19, 25, 22, 24, 28, 27, 26, 30, 35};
  for (int i = 0; i < 10; i++) {
    cin >> dices[i];
  }
  ret = -1;
}

bool notInCurr(int loc, vi curr) {
  for (auto it : curr) {
    if (it == loc) return false;
  }
  return true;
}

void go(int idx, int score, vi curr) {
  if (idx == 10) {
    ret = max(ret, score);
    return;
  }

  for (int i = 0; i < 4; i++) {
    int loc = curr[i];

    if (graph[loc].size() > 1) {
      loc = graph[loc][1];
    } else {
      loc = graph[loc][0];
    }

    for (int _ = 0; _ < dices[idx] - 1; _++) {
      loc = graph[loc][0];
    }

    if (loc == 21 || (loc != 21 && notInCurr(loc, curr))) {
      vi temp = curr;
      curr[i] = loc;
      go(idx + 1, score + scores[loc], curr);
      curr = temp;
    }
  }
}

int main() {
  fastIO;
  init();
  go(0, 0, {0, 0, 0, 0});
  cout << ret << "\n";
  return 0;
}