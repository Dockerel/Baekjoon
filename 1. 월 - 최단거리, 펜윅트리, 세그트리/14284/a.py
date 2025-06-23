import sys, heapq
from collections import defaultdict

input = sys.stdin.readline

n, m = map(int, input().split())

parent = [i for i in range(n + 1)]

edges = defaultdict(list)
for _ in range(m):
    a, b, c = map(int, input().split())
    edges[a].append((c, b))
    edges[b].append((c, a))

s, t = map(int, input().split())

pq = [(0, s)]
heapq.heapify(pq)

dist = [float("inf") for _ in range(n + 1)]
dist[s] = 0

visited = [0] * (n + 1)

while pq:
    _, curr_node = heapq.heappop(pq)
    if visited[curr_node]:
        continue
    visited[curr_node] = 1
    for next_weight, next_node in edges[curr_node]:
        if dist[curr_node] + next_weight < dist[next_node]:
            dist[next_node] = dist[curr_node] + next_weight
            heapq.heappush(pq, (dist[curr_node] + next_weight, next_node))

print(dist[t])
