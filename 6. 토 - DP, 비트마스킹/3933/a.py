import sys

input = sys.stdin.readline

nums = []
while True:
    n = int(input())
    if n == 0:
        break
    nums.append(n)

max_num = max(nums)

dp = [[0 for _ in range(max_num + 1)] for _ in range(5)]
dp[0][0] = 1

for i in range(1, int(max_num**0.5) + 1):
    for j in range(1, 4 + 1):
        for k in range(i**2, max_num + 1):
            dp[j][k] += dp[j - 1][k - i**2]

for num in nums:
    print(dp[1][num] + dp[2][num] + dp[3][num] + dp[4][num])
