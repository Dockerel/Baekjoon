import sys
from collections import deque

input = sys.stdin.readline

n, m = map(int, input().split())

indegree = [0] * (n + 1)
graph = [[] for _ in range(n + 1)]
semester = [1] * (n + 1)

for _ in range(m):
    a, b = map(int, input().split())
    graph[a].append(b)
    indegree[b] += 1

queue = deque()

for i in range(1, n + 1):
    if indegree[i] == 0:
        queue.append(i)

while queue:
    curr = queue.popleft()
    for nxt in graph[curr]:
        indegree[nxt] -= 1

        semester[nxt] = max(semester[nxt], semester[curr] + 1)
        if indegree[nxt] == 0:
            queue.append(nxt)

print(*semester[1:])
