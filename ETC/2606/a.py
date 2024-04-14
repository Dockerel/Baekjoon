from collections import defaultdict,deque
import sys
input=sys.stdin.readline
n=int(input())
e=int(input())
graph=defaultdict(list)
for _ in range(e):
    n1,n2=list(map(int,input().rstrip().split()))
    graph[n1].append(n2)
    graph[n2].append(n1)
v=defaultdict(int)
q=deque([1])
v[1]=1
while q:
    node=q.popleft()
    for nd in graph[node]:
        if v[nd]==0:
            q.append(nd)
            v[nd]=1
print(len(v)-1)