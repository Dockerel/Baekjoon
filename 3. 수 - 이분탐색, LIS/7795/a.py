import sys, bisect

input=sys.stdin.readline

def go():
    n,m=list(map(int,input().split()))
    l1=sorted(list(map(int,input().split())))
    l2=sorted(list(map(int,input().split())))

    cnt=0
    for a in l1:
        cnt += bisect.bisect_left(l2, a)

    print(cnt)

t=int(input())
for _ in range(t):
    go()