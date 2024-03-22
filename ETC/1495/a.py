import sys
input=sys.stdin.readline
n,s,m=list(map(int,input().split()))
v=[0]+list(map(int,input().split()))

dp=[[0]*(m+4) for _ in range(n+4)]
dp[0][s]=1

for i in range(1,n+1):
    for j in range(0,m+1):
        if dp[i-1][j]==1:
            if j+v[i]<=m: dp[i][j+v[i]]=1
            if j-v[i]>=0: dp[i][j-v[i]]=1

for j in range(m,-1,-1):
    if dp[n][j]==1:
        print(j)
        exit(0)
print(-1)