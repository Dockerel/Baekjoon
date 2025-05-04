import sys

input = sys.stdin.readline

graph = {}
for _ in range(int(input())):
    _from, _to = list(map(str, input().strip().split(" is ")))
    if graph.get(_from) == None:
        graph[_from] = []
    graph[_from].append(_to)


def go(visited, curr, target):
    if curr == target:
        return 1
    if graph.get(curr):
        for node in graph[curr]:
            if visited.get(node) == None:
                visited[node] = 1
                return go(visited, node, target)
    return 0


for _ in range(int(input())):
    _from, _to = list(map(str, input().strip().split(" is ")))
    visited = {_from: 1}
    print("T" if go(visited, _from, _to) else "F")
