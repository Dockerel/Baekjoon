import sys

input=sys.stdin.readline

v, e = map(int, sys.stdin.readline().split())
graph = [[float('inf')] * v for _ in range(v)]
for _ in range(e):
    a, b, c = map(int, sys.stdin.readline().split())
    graph[a-1][b-1] = c

for k in range(v):
    for i in range(v):
        for j in range(v):
            graph[i][j]=min(graph[i][j],graph[i][k] + graph[k][j])

answer = float('inf')
for i in range(v):
    for j in range(v):
        answer = min(answer, graph[i][j] + graph[j][i])

if answer == float('inf'):
    print('-1')
else:
    print(answer)