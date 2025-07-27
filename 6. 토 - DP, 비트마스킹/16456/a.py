n = int(input())

dp = [0] * (50000 + 1)
dp[:6] = [0, 1, 1, 2, 3, 4]

for i in range(6, n + 1):
    dp[i] = (dp[i - 1] + dp[i - 3]) % 1000000009

print(dp[n])
