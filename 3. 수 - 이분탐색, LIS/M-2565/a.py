import sys

input=sys.stdin.readline

n=int(input())
a=[]
for _ in range(n):
    a.append(list(map(int,input().split())))

a=list(map(lambda x:x[1],sorted(a)))

dp=[1]*n
for i in range(n):
    for j in range(i):
      if a[j]<a[i]:
        dp[i]=max(dp[i],dp[j]+1)

print(n-max(dp))