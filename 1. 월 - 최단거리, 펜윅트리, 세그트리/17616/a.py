import sys
from collections import defaultdict, deque

input = sys.stdin.readline

n, m, x = map(int, input().split())

graph = defaultdict(list)
rgraph = defaultdict(list)
for _ in range(m):
    p1, p2 = map(int, input().split())
    graph[p1].append(p2)
    rgraph[p2].append(p1)

visited = set()
rvisited = set()

q = deque()
q.append(x)
while q:
    curr = q.popleft()
    for nxt in graph[curr]:
        if nxt not in visited:
            visited.add(nxt)
            q.append(nxt)
q.append(x)
while q:
    curr = q.popleft()
    for nxt in rgraph[curr]:
        if nxt not in rvisited:
            rvisited.add(nxt)
            q.append(nxt)

front = len(rvisited)
back = len(visited)
unknown = n - 1 - front - back

print(f"{front+1} {front+unknown+1}")
