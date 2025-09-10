#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n;
int a[1004];
int max_len,max_idx;
queue<int> q;
int visited[1004];

void init() {
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    max_len=-1;
    max_idx=0;
}

void bfs(int num){
    int length=0;
    memset(visited,0,sizeof(visited));
    q.push(num);
    while(!q.empty()){
        int curr=q.front();
        q.pop();
        visited[curr]=1;
        length++;
        int next=a[curr];
        if(!visited[next]){
            q.push(next);
        }
    }
    if(max_len<length){
        max_len=length;
        max_idx=num;
    }
}

void go() {
    for(int i=1;i<=n;i++){
        // bfs해서 max 찾기
        bfs(i);
    }
    cout<<max_idx<<"\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}