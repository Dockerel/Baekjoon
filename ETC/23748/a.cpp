#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define INF 54
#define pii pair<int,int>

using namespace std;

int n,tx,ty;
int x,y;
vector<pii> xys;

pii dp[104][104]; // x,y 할당량을 채울라면 팔아야하는 최소 고객의 수

void init() {
    cin>>n>>tx>>ty;
    for(int _=0;_<n;_++){
        cin>>x>>y;
        xys.push_back({x,y});
    }

    for(int i=0;i<=tx;i++){
        for(int j=0;j<=ty;j++){
            dp[i][j]={INF,0};
        }
    }

    dp[0][0]={0,0};
}

void go() {
    for(int i=0;i<=tx;i++){
        for(int j=0;j<=ty;j++){
            for(int k=0;k<xys.size();k++){
                
            }
        }
    }
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}