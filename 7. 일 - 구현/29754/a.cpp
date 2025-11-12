#include <bits/stdc++.h>
#define fastIO ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

// 매주 5회 이상
// 매주 60시간 이상
// 하는 버튜버 찾기

int n, m;
string input;

map<string, int> nameToIndex;

int dateTable[104][55];  // i 번째 버튜버는 j 번째 주에 dateTable[i][j]번 방송
int timeTable[104][55];  // i 번째 버튜버는 j 번째 주에 timeTable[i][j]분 방송

vector<string> split(const string& input, string delim) {
  vector<string> result;
  int start = 0;
  int end = input.find(delim);
  while (end != string::npos) {
    result.push_back(input.substr(start, end - start));
    start = end + delim.size();
    end = input.find(delim, start);
  }
  result.push_back(input.substr(start));
  return result;
}

void init() { cin >> n >> m; }

void go() {
  int currIndex = 0;
  for (int i = 0; i < n; i++) {
    string name, dateString, startTime, endTime;
    cin >> name >> dateString >> startTime >> endTime;
    int date = stoi(dateString) - 1;

    auto it2 = nameToIndex.find(name);
    if (it2 == nameToIndex.end()) {
      nameToIndex[name] = currIndex++;
    }

    // date
    int index = nameToIndex[name];
    dateTable[index][date / 7] += 1;

    // time
    auto time1 = split(startTime, ":");
    auto time2 = split(endTime, ":");
    timeTable[index][date / 7] += (stoi(time2[0]) * 60 + stoi(time2[1])) -
                                  (stoi(time1[0]) * 60 + stoi(time1[1]));
  }

  vector<string> ret;
  for (auto it : nameToIndex) {
    string name = it.first;
    int index = it.second;

    bool isReal = true;
    for (int i = 0; i < m / 7; i++) {
      if (dateTable[index][i] < 5 || timeTable[index][i] < 3600) {
        isReal = false;
        break;
      }
    }
    if (isReal) {
      ret.push_back(name);
    }
  }

  if (ret.size() > 0) {
    sort(ret.begin(), ret.end());
    for (auto it : ret) {
      cout << it << "\n";
    }
  } else {
    cout << "-1\n";
  }
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}