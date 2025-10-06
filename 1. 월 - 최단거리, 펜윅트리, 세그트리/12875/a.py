import sys
from collections import defaultdict

input = sys.stdin.readline

n = int(input())

d = int(input())

graph = [[0] * n for _ in range(n)]

for i in range(n):
    s = input().strip()
    for j in range(n):
        if i == j:
            continue
        if s[j] == "Y":
            graph[i][j] = 1
        else:
            graph[i][j] = float("inf")

for k in range(n):
    for i in range(n):
        for j in range(n):
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])

max_len = -1
for i in range(n):
    for j in range(n):
        if graph[i][j] == float("inf"):
            print(-1)
            exit(0)
        max_len = max(max_len, graph[i][j])

print(max_len * d)
