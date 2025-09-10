import sys

input = sys.stdin.readline

n = int(input())
_list = [0] + list(map(int, input().split()))

dp = [0] * (n + 1)
ret = -sys.maxsize

for i in range(1, n + 1):
    dp[i] = max(_list[i], dp[i - 1] + _list[i])
    ret = max(ret, dp[i])
print(ret)
