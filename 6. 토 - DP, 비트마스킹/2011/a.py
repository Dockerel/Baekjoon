import sys

input = sys.stdin.readline

s = input().strip()

dp = [0] * (len(s) + 1)

if s[0] == "0":
    print(0)
    exit(0)

dp[0] = dp[1] = 1

for i in range(2, len(s) + 1):
    if s[i - 1] != "0":
        dp[i] += dp[i - 1]

    num = s[i - 2 : i]
    if 10 <= int(num) <= 26:
        dp[i] += dp[i - 2]

    dp[i] %= 1000000

print(dp[len(s)] % 1000000)
