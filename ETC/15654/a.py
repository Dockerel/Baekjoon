import sys
from itertools import permutations as perm

input=sys.stdin.readline

n,m=map(int,input().split())
l1=sorted(list(map(int,input().split())))

perms=list(perm([i for i in range(n)], m))
for p in perms:
    for idx in p:
        print(l1[idx], end=" ")
    print()