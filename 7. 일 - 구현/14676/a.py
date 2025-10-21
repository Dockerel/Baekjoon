import sys

input = sys.stdin.readline

n, m, k = map(int, input().split())

indegree = [0] * (n + 1)
graph = [[] for i in range(n + 1)]
buildings = [0] * (n + 1)
available = False

for _ in range(m):
    x, y = map(int, input().split())
    graph[x].append(y)
    indegree[y] += 1

for _ in range(k):
    cmd, num = map(int, input().split())
    if cmd == 1:
        if indegree[num] != 0:
            available = True
            break
        buildings[num] += 1
        if buildings[num] == 1:
            for next in graph[num]:
                indegree[next] -= 1

    else:
        if buildings[num] <= 0:
            available = True
            break
        buildings[num] -= 1
        if buildings[num] == 0:
            for next in graph[num]:
                indegree[next] += 1

if available:
    print("Lier!")
else:
    print("King-God-Emperor")
