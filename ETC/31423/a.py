import sys
from collections import defaultdict

sys.setrecursionlimit(500004)

input = sys.stdin.readline

n = int(input())

in_degree = [0] * (n + 4)

univs = [""] + [input().strip() for _ in range(n)]

graph = defaultdict(list)

for _ in range(n - 1):
    i, j = list(map(int, input().split()))
    graph[i].append(j)
    in_degree[j] += 1

# 그래프 출발점 찾기
start = -1
for i in range(1, n + 1):
    if in_degree[i] == 0:
        start = i


def go(curr):
    print(univs[curr], end="")
    for next in graph[curr]:
        go(next)


go(start)
print()
