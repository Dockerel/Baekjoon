import sys

input = sys.stdin.readline

n, k = map(int, input().split())

graph = [[0] * (n + 1) for _ in range(n + 1)]
for i in range(n + 1):
    for j in range(n + 1):
        if i != j:
            graph[i][j] = float("inf")

for _ in range(k):
    first, second = map(int, input().split())
    graph[first][second] = 1

for k in range(n + 1):
    for i in range(n + 1):
        for j in range(n + 1):
            graph[i][j] = min(graph[i][j], graph[i][k] + graph[k][j])

ret = []
for _ in range(int(input())):
    n1, n2 = map(int, input().split())
    if graph[n1][n2] != float("inf"):
        ret.append(-1)
    elif graph[n2][n1] != float("inf"):
        ret.append(1)
    else:
        ret.append(0)

print(*ret, sep="\n")
