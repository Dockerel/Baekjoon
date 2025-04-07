#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#define pii pair<int,int>
#define MAX 987654321

using namespace std;

int n,n1,n2;
vector<int> graph[54];

int v[54];
int score[54];

queue<pii> q;

int curr,currScore;

void init() {
    cin>>n;
    while(1){
        cin>>n1>>n2;
        if(n1==-1&&n2==-1){
            break;
        }
        graph[n1].push_back(n2);
        graph[n2].push_back(n1);
    }
}

void go() {
    // 노드마다 bfs 돌려서 거리의 합을 저장해두고
    // 가장 작은 score 가지는 후보들의 거리의 합, 후보들 수, 후보 출력
    
    int minScore=MAX;
    for(int i=1;i<=n;i++){
        memset(v,0,sizeof(v));
        while(!q.empty()) q.pop();
        q.push({i,0});
        v[i]=1;
        
        int tempScore=-1;
        while(!q.empty()){
            tie(curr,currScore)=q.front();
            q.pop();

            tempScore=max(tempScore,currScore);

            for(auto it:graph[curr]){
                if(!v[it]){
                    q.push({it,currScore+1});
                    v[it]=1;
                }
            }
        }
        score[i]=tempScore;
        minScore=min(minScore,tempScore);
    }

    vector<int> ret;
    for(int i=1;i<=n;i++){
        if(score[i]==minScore){
            ret.push_back(i);
        }
    }
    cout<<minScore<<" "<<ret.size()<<"\n";
    for(auto it:ret){
        cout<<it<<" ";
    }
    cout<<"\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}