import sys

input = sys.stdin.readline

n = int(input())
wins = [0] + list(map(int, input().split()))
m = int(input())
loses = [0] + list(map(int, input().split()))
k = int(input())

# 4
# 50 30 70 90
# 2
# 100 100
# 110
# -> 160

# i 번째 승리면 wins_i
# 현재 점수가 a*k+b : a는 정수, 0<b<k
# 이 상태에서 패배 시 min(loses_i, b)
# 현재 점수가 a*k : k의 배수
# 이 상태에서 패배 시 loses_i

# dp[i][j] : 승리 i번, 패배 j번 일 때의 최대점수
dp = [[-float("inf")] * (m + 4) for _ in range(n + 4)]
dp[0][0] = 0
for i in range(n + 1):
    for j in range(m + 1):
        # i번째 승리, l번째 패배면 i-1번째 승리 or l-1 번째 패배 확인해야 함
        # i-1 번째 승리에서 승리하는 경우
        if i - 1 >= 0 and dp[i - 1][j] != -float("inf"):
            dp[i][j] = max(dp[i][j], dp[i - 1][j] + wins[i])
        # l-1 번째 패배에서 패배하는 경우
        if j - 1 >= 0 and dp[i][j - 1] != -float("inf"):
            prev_score = dp[i][j - 1]
            if prev_score % k == 0:
                dp[i][j] = max(dp[i][j], prev_score - loses[j])
            else:
                dp[i][j] = max(dp[i][j], prev_score - min(loses[j], prev_score % k))

print(dp[n][m])
