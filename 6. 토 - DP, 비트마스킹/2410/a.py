n = int(input())

dp = [0] * (n + 1)
dp[0] = 1

for i in range(1, n + 1):
    if i % 2:
        dp[i] = (dp[i - 1]) % 1000000000
    else:
        dp[i] = (dp[i - 1] + dp[i // 2]) % 1000000000

print(dp[n])
