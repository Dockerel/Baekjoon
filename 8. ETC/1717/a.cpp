#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n,m;
int c,a,b;
vector<int> parent;

void init() {
    cin>>n>>m;
    for(int i=0;i<=n;i++){
        parent.push_back(i);
    }
}

int findParent(int x){
    if(parent[x]!=x){
        parent[x]=findParent(parent[x]);
    }
    return parent[x];
}

void go() {
    for(int i=0;i<m;i++){
        cin>>c>>a>>b;

        int parent_a=findParent(a);
        int parent_b=findParent(b);

        if(c==0){
            if(parent_a>parent_b){
                parent[parent_a]=parent_b;
            }else{
                parent[parent_b]=parent_a;
            }
        }else{
            cout<<(parent_a==parent_b ? "YES\n" : "NO\n");
        }
    }
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}