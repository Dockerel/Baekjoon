n = int(input())

dp = [0] * 101

dp[:7] = [i for i in range(7)]

# n-3에서 acv 시행
# n-4에서 acvv 시행
# n-5에서 acvvv 시행

for i in range(7, 101):
    dp[i] = max([dp[i - 3] * 2, dp[i - 4] * 3, dp[i - 5] * 4])

# print(dp[n])
print(dp)
