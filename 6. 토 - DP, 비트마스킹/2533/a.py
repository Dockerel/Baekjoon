import sys
from collections import defaultdict

sys.setrecursionlimit(1_000_000)

input = sys.stdin.readline

n = int(input())
graph = defaultdict(list)
for _ in range(n - 1):
    n1, n2 = map(int, input().split())
    graph[n1].append(n2)
    graph[n2].append(n1)

dp = [[0, 1] for _ in range(n + 1)]
visited = [0] * (n + 1)


def go(curr):
    global dp, visited
    visited[curr] = 1

    for nxt in graph[curr]:
        if visited[nxt]:
            continue
        go(nxt)
        dp[curr][0] += dp[nxt][1]
        dp[curr][1] += min(dp[nxt][0], dp[nxt][1])


go(1)
print(min(dp[1]))
