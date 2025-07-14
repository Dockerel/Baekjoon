import sys
from collections import defaultdict

input = sys.stdin.readline
n, m = map(int, input().split())

graph = defaultdict(list)
r_graph = defaultdict(list)
visited = None

temp = None
ret = 0

for _ in range(m):
    frm, to = map(int, input().split())
    graph[frm].append(to)
    r_graph[to].append(frm)


def get_graph(reversed):
    return r_graph if reversed else graph


def dfs(curr, reversed=False):

    global visited, temp

    curr_graph = get_graph(reversed)

    visited[curr] = 1
    for node in curr_graph[curr]:
        if not visited[node]:
            temp += 1
            dfs(node, reversed)


for i in range(1, n + 1):
    temp = 0
    visited = [0] * (n + 1)
    dfs(i)
    visited = [0] * (n + 1)
    dfs(i, True)
    ret += 1 if temp == n - 1 else 0

print(ret)
