#include <bits/stdc++.h>
using namespace std;
char s[104];
int palindrome(){
    int n=strlen(s);
    for(int i=0;i<n/2;i++){
        if(s[i]!=s[n-i-1]) return 0;
    }
    return 1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>s;
    if(palindrome()) cout<<"1\n";
    else cout<<"0\n";
    return 0;
}