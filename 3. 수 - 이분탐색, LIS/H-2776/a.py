import sys

input=sys.stdin.readline

t=int(input())

for _ in range(t):
    d={}
    n=int(input())
    l1=list(map(int,input().split()))
    m=int(input())
    l2=list(map(int,input().split()))

    for num in l1:
        d[num]=1
    for num in l2:
        if d.get(num)==None:
            print(0)
        else:
            print(1)