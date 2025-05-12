import sys

input = sys.stdin.readline

n, k = list(map(int, input().split()))

graph = {}

start = None

d = [[float("Inf")] * (n + 1) for _ in range(n + 1)]
for i in range(1, n + 1):
    d[i][i] = 0

for _ in range(k):
    a, b = list(map(int, input().split()))

    d[a][b] = 1
    d[b][a] = 1

    if graph.get(a) == None:
        graph[a] = []
    graph[a].append(b)
    if graph.get(b) == None:
        graph[b] = []
    graph[b].append(a)

for m in range(1, n + 1):
    for i in range(1, n + 1):
        for j in range(1, n + 1):
            d[i][j] = min(d[i][j], d[i][m] + d[m][j])

for i in range(1, n + 1):
    for j in range(1, n + 1):
        if d[i][j] > 6:
            print("Big World!")
            exit(0)
print("Small World!")
