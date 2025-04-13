#include <bits/stdc++.h>
using namespace std;
int main() {
    int n,f;
    vector<int> a;
    while(1){
        cin>>n;
        if(n==0)break;
        a.push_back(n);
    }
    int m=*max_element(a.begin(),a.end());
    long long s[10000004]={0};
    for(int i=2;i<=m;i++)s[i]=1;
    for(int i=2;i<=int(sqrt(m))+1;i++)
        for(int j=i;j<=m/i+1;j++){
            s[i*j]+=i;
            if(i!=j)s[i*j]+=j;
        }
    for(int q:a){
        cout<<"\nAmicable numbers between 1 and "<<q<<"\n";
        f=1;
        for(int i=2;i<=q;i++){
            if(s[i] != i && i < s[i] && s[s[i]] == i){
                f=0;
                cout<<i<<" "<<s[i]<<"\n";
            }
        }
        if(f)cout<<"None\n";
    }
}