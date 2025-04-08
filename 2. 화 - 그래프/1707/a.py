import sys

sys.setrecursionlimit(100000)

input = sys.stdin.readline

for _ in range(int(input())):
    v, e = list(map(int, input().split()))

    graph = [[] for i in range(v + 4)]

    for i in range(e):
        n1, n2 = list(map(int, input().split()))
        graph[n1].append(n2)
        graph[n2].append(n1)

    def dfs(visited, curr, prev):
        for node in graph[curr]:
            if visited[node] == 0:
                color = 2 if prev == 1 else 1
                visited[node] = color
                dfs(visited, node, color)

    # dfs나 bfs 쳐서 사이클 나타나는지 확인
    visited = [0] * (v + 4)
    for i in range(1, v + 1):
        if visited[i] == 0:
            visited[i] = 1
            dfs(visited, i, 1)

    flag = 0
    for i in range(1, v + 1):
        color = visited[i]
        for node in graph[i]:
            if color == visited[node]:
                flag = 1
                break
        if flag:
            break
    print("NO" if flag else "YES")
