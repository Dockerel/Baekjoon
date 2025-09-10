import sys

input=sys.stdin.readline

n=int(input())

dp=[0]*n

a=[]
for i in range(n):
    f=float(input())
    a.append(f)
    dp[i]=f

for i in range(1,n):
    dp[i]=max(dp[i],dp[i-1]*a[i])

print("%0.3f"%max(dp))