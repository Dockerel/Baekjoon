import sys
from itertools import permutations as perm

input=sys.stdin.readline

n,m=map(int,input().split())
l1=sorted(list(map(int,input().split())))

ret=set()

perms=perm([i for i in range(n)], m)

for p in perms:
    temp=[]
    for i in p:
        temp.append(l1[i])
    ret.add(tuple(temp))

ret=sorted(ret)

for ans in ret:
    print(*ans)