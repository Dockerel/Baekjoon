import sys
from collections import defaultdict, deque

input = sys.stdin.readline

n, k = map(int, input().split())

codes = [""] + [input().strip() for _ in range(n)]

frm, to = map(int, input().split())

graph = defaultdict(list)


def hamming_dist(c1, c2):
    temp = int(c1, 2) ^ int(c2, 2)
    return temp > 0 and (temp & (temp - 1) == 0)


for i in range(1, n):
    for j in range(i + 1, n + 1):
        if hamming_dist(codes[i], codes[j]):
            graph[i].append(j)
            graph[j].append(i)

q = deque()
q.append((frm, 0, f"{frm}"))

visited = [0] * (n + 4)
visited[frm] = 1

while q:
    curr, curr_dist, curr_path = q.popleft()
    for node in graph[curr]:
        if visited[node]:
            continue
        if node == to:
            print(f"{curr_path} {node}")
            exit(0)
        visited[node] = 1
        q.append((node, curr_dist + 1, f"{curr_path} {node}"))
print(-1)
