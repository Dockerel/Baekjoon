#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int n;
long long ret;

void init() {
    cin>>n;
}

void go() {
    for(int i=2;i<=n;i++){
        ret+=(n/i-1)*i;
        ret%=1000000;
    }
    cout<<ret<<"\n";
}

int main() {
  fastIO;
  init();
  go();
  return 0;
}