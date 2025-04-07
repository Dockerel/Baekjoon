import sys

input=sys.stdin.readline

t=int(input())

for _ in range(t):
    p,q,r=list(map(int,input().split()))
    print((p*min(q,r))%1000000007)