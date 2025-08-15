import sys

input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))

# 연속된 몇 개의 수를 선택해서 구할 수 있는 가장 큰 합
# 수 하나 이상 선택
# 수열에서 수를 하나 제거 가능

dp = [[0] * n for _ in range(2)]

# dp[0][i] : 아무것도 안뺀 상태에서 최대 합
# dp[1][i] : 하나 뺀 상태에서 최대 합

dp[0][0] = a[0]

ret = a[0]
for i in range(1, n):
    num = a[i]
    dp[0][i] = max(dp[0][i - 1] + num, num)
    dp[1][i] = max(dp[0][i - 1], dp[1][i - 1] + num)
    ret = max(ret, max(dp[0][i], dp[1][i]))

print(ret)
