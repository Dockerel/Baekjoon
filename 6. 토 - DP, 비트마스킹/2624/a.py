import sys

input = sys.stdin.readline
t = int(input())
dp = [1] + [0] * t
for _ in range(int(input())):
    p, n = list(map(int, input().split()))
    for i in range(t, -1, -1):
        for j in range(p, p * n + 1, p):
            if i - j >= 0 and dp[i - j]:
                dp[i] += dp[i - j]
print(dp[t])
