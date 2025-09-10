import sys

input=sys.stdin.readline

n,m=list(map(int,input().split()))

sys.setrecursionlimit(1000000)

parent=[0]*(n+1)
for i in range(n+1):
    parent[i]=i

def findParent(x):
    if parent[x]==x:
        parent[x]=findParent(parent[x])
    return parent[x]

for _ in range(m):
    cmd,a,b=list(map(int,input().split()))

    parent_a=findParent(a)
    parent_b=findParent(b)

    if cmd==0:
        if parent_a>parent_b:
            parent[parent_a]=parent_b
        else:
            parent[parent_b]=parent_a
    else:
        if parent_a==parent_b:
            print("YES")
        else:
            print("NO")