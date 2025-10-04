import sys
from collections import defaultdict

input = sys.stdin.readline

n, m = map(int, input().split())

graph = defaultdict(list)
for _ in range(m):
    n1, n2 = map(int, input().split())
    graph[n1].append(n2)
    graph[n2].append(n1)

DIV = 10**9 + 7

ret = 0

dp = [[-1] * 8 for _ in range(100004)]


def go(curr, currLen):
    if currLen == 7:
        return 1
    if dp[curr][currLen] != -1:
        return dp[curr][currLen]
    dp[curr][currLen] = 0
    for node in graph[curr]:
        dp[curr][currLen] += go(node, currLen + 1) % DIV

    return dp[curr][currLen] % DIV


for i in range(1, n + 1):
    ret += go(i, 0)

print(ret % DIV)
