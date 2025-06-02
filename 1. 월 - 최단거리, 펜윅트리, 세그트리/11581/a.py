import sys

input = sys.stdin.readline
n = int(input())
graph = {}
for i in range(1, n):
    input()
    graph[i] = list(map(int, input().split()))

v = [0] * (n + 1)
v[1] = 1


def go(curr):

    global v

    if graph.get(curr) == None:
        return
    for node in graph[curr]:
        if v[node]:
            print("CYCLE")
            exit(0)
        v[node] = 1
        go(node)
        v[node] = 0


go(1)
print("NO CYCLE")
