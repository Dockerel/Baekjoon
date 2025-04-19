#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n,num,ret;
priority_queue<int,vector<int>,less<int>> pq;

void init() {
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num;
        pq.push(num);
    }
    ret=0;
}

void go() {
    while(pq.size()>=2){
        int n1=pq.top();
        pq.pop();
        int n2=pq.top();
        pq.pop();
        ret+=(n1*n2);
        pq.push(n1+n2);
    }
    cout<<ret<<"\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}