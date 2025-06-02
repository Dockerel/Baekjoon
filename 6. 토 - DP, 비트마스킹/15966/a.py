import sys

input = sys.stdin.readline
int(input())
a = list(map(int, input().split()))
dp = {}
max_len = -1
for n in a:
    dp[n] = dp.get(n - 1, 0) + 1
    max_len = max(max_len, dp[n])
print(max_len)
