import sys

input = sys.stdin.readline

a, b, c, k = map(int, input().split())

#  0
# 3 1
#  2


def turnL(curr):
    return 3 if curr == 0 else curr - 1


def turnR(curr):
    return 0 if curr == 3 else curr + 1


def turnB(curr):
    return (curr + 2) % 4


dp = [
    [float("inf")] * (k + 4) for _ in range(4)
]  # dp[i][j] : i 방향이 되게 하는 방향으로 j 만큼 소비했을 때 제식 수행 횟수 최솟값
dp[0][0] = 0

for i in range(1, k + 1):
    for j in range(4):
        # j로 보게 - turnL
        curr = turnR(j)
        if i - a >= 0 and dp[curr][i - a] >= 0:
            dp[j][i] = min(dp[j][i], dp[curr][i - a] + 1)
        # j로 보게 - turnR
        curr = turnL(j)
        if i - b >= 0 and dp[curr][i - b] >= 0:
            dp[j][i] = min(dp[j][i], dp[curr][i - b] + 1)
        # j로 보게 - turnB
        curr = turnB(j)
        if i - c >= 0 and dp[curr][i - c] >= 0:
            dp[j][i] = min(dp[j][i], dp[curr][i - c] + 1)

print(-1 if dp[0][k] == float("inf") else dp[0][k])
