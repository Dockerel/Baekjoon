import sys

input = sys.stdin.readline
nums = [int(input()) for _ in range(int(input()))]

max_num = max(nums)
temp = 1000000009

dp = [[0 for _ in range(3)] for _ in range(max_num + 1)]

dp[1] = [1, 0, 0]
dp[2] = [0, 1, 0]
dp[3] = [1, 1, 1]

for i in range(4, max_num + 1):
    dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % temp
    dp[i][1] = (dp[i - 2][0] + dp[i - 2][2]) % temp
    dp[i][2] = (dp[i - 3][0] + dp[i - 3][1]) % temp

for num in nums:
    print(sum(dp[num]) % temp)
