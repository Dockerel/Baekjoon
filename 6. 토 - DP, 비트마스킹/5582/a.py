import sys

input = sys.stdin.readline
s1, s2 = input().strip(), input().strip()
dp = [[0] * (len(s2) + 2) for _ in range(len(s1) + 2)]

ret = 0

for i in range(1, len(s1) + 1):
    for j in range(1, len(s2) + 1):
        if s1[i - 1] == s2[j - 1]:
            dp[i][j] = dp[i - 1][j - 1] + 1
            ret = max(ret, dp[i][j])

print(ret)
