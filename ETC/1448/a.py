import sys

input=sys.stdin.readline

n=int(input())

a=sorted([int(input()) for _ in range(n)])

for i in range(len(a)-1,1,-1):
    if a[i]<a[i-1]+a[i-2]:
        print(a[i]+a[i-1]+a[i-2])
        exit(0)

print(-1)