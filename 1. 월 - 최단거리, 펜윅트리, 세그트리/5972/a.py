import sys
from heapq import heappush,heappop
from collections import defaultdict

input=sys.stdin.readline

n,m=list(map(int,input().split()))
graphs=defaultdict(list)
for _ in range(m):
    a,b,c=list(map(int,input().split()))
    graphs[a].append([b,c])
    graphs[b].append([a,c])

dist=[sys.maxsize]*(n+1)
dist[1]=0
h=[[dist[i],i] for i in range(1,n+1)]

visited=set()

while h:
    _,curr=heappop(h)
    if curr in visited:
        continue
    visited.add(curr)

    for nxt, w in graphs[curr]:
        if dist[curr]+w<dist[nxt]:
            dist[nxt]=dist[curr]+w
            heappush(h,[dist[nxt],nxt])

print(dist[n])