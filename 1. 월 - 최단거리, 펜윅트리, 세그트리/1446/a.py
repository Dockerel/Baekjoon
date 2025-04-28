import sys
from collections import defaultdict

MAX = 10004

input = sys.stdin.readline
n, d = list(map(int, input().split()))
routes = defaultdict(dict)
for _ in range(n):
    start, end, length = list(map(int, input().split()))
    if end > d:
        continue
    if routes[start].get(end) == None:
        routes[start][end] = MAX
    routes[start][end] = min(routes[start][end], length)

dp = [i for i in range(d + 1)]

routes = sorted(routes.items(), key=lambda x: x[0])

for route in routes:
    start = route[0]
    for end, length in route[1].items():
        prev = dp[end]
        dp[end] = min(dp[end], dp[start] + length, dp[start] + end - start)
        if prev != dp[end]:
            for i in range(d - end + 1):
                dp[end + i] = min(dp[end + i], dp[end] + i)

print(dp[d])
