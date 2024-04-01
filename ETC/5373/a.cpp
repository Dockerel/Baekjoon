#include <bits/stdc++.h>
#define fastIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

using namespace std;

int t, n;
string cmd;
char u[3][3],d[3][3],f[3][3],b[3][3],l[3][3],r[3][3];

int main() {
  fastIO;

  cin >> t;
  while (t--) {
    cin >> n;
    fill(u[0],u[3],'w');
    fill(d[0],d[3],'y');
    fill(f[0],f[3],'r');
    fill(b[0],b[3],'o');
    fill(l[0],l[3],'g');
    fill(r[0],r[3],'b');
    for (int i = 0; i < n; i++) {
      cin >> cmd;
      if(!cmd.compare("U+")){
        
      }
      else if(!cmd.compare("U-")){}
      else if(!cmd.compare("D+")){}
      else if(!cmd.compare("D-")){}
      else if(!cmd.compare("F+")){}
      else if(!cmd.compare("F-")){}
      else if(!cmd.compare("B+")){}
      else if(!cmd.compare("B-")){}
      else if(!cmd.compare("L+")){}
      else if(!cmd.compare("L-")){}
      else if(!cmd.compare("R+")){}
      else if(!cmd.compare("R-")){}
    }
  }

  return 0;
}