import sys

input = sys.stdin.readline

d, p = map(int, input().split())

dp = [0] * (d + 1)
dp[0] = 0

for _ in range(p):
    l, c = map(int, input().split())
    for i in range(d, l - 1, -1):
        if i - l == 0:
            dp[i] = max(dp[i], c)
            continue
        dp[i] = max(dp[i], min(dp[i - l], c))

print(dp[d])
