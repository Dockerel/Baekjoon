#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n;
vector<string> univs;
string univ;

void init() {
    cin>>n;
    univs.push_back("");
    for(int i=0;i<n;i++){
        cin>>univ;
        univs.push_back(univ);
    }
}

void go() {
    int i,j;
    for(int _=0;_<n-1;_++){
        cin>>i>>j;
        univs[i]+=univs[j];
        univs[j]="";
    }
    for(auto it:univs){
        cout<<it;
    }
    cout<<"\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}