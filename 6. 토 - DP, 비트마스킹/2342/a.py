import sys

input = sys.stdin.readline

INF = float("inf")

steps = [0] + list(map(int, input().split()))[:-1]
n = len(steps)

need_power = [[0] * 5 for _ in range(5)]
for i in range(5):
    for j in range(5):
        if i == j:
            need_power[i][j] = 1
        elif i == 0 or j == 0:
            need_power[i][j] = 2
        elif (i + j) % 2 == 1:
            need_power[i][j] = 3
        else:
            need_power[i][j] = 4

# steps[i]에서 왼발로 loc1, 오른발로 loc2에 있을 때 최소 힘
dp = [[[INF] * 5 for _ in range(5)] for _ in range(n)]
dp[0][0][0] = 0
for i in range(1, n):
    target_loc = steps[i]
    for left in range(5):
        for right in range(5):
            if dp[i - 1][left][right] == INF:
                continue
            dp[i][target_loc][right] = min(
                dp[i][target_loc][right],
                dp[i - 1][left][right] + need_power[left][target_loc],
            )
            dp[i][left][target_loc] = min(
                dp[i][left][target_loc],
                dp[i - 1][left][right] + need_power[right][target_loc],
            )

print(min([min(powers) for powers in dp[-1]]))
