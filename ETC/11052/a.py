import sys
input=sys.stdin.readline
n=int(input())
p=[0]+list(map(int,input().rstrip().split()))
mem=[0]*(n+1)

def dp(n):
    if mem[n]>0:
        return mem[n]
    if n==0:
        return 0
    q=-sys.maxsize
    for i in range(1,n+1):
        q=max(q,p[i]+dp(n-i))
    mem[n]=q
    return mem[n]


print(dp(n))