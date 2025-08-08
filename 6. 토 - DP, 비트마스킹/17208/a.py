import sys

input = sys.stdin.readline

orderN, cheeseN, friesN = map(int, input().split())

# dp[i][j] : i개의 치즈버거와 j개의 감자튀김을 사용했을 때 처리 가능한 최대 주문
dp = [[-1] * (friesN + 4) for _ in range(cheeseN + 4)]
dp[0][0] = 0

for _ in range(orderN):
    cheese, fries = map(int, input().split())
    for i in range(cheeseN, cheese - 1, -1):
        for j in range(friesN, fries - 1, -1):
            if dp[i - cheese][j - fries] == -1:
                continue
            dp[i][j] = max(dp[i][j], dp[i - cheese][j - fries] + 1)

ret = -1
for i in range(0, cheeseN + 1):
    for j in range(0, friesN + 1):
        ret = max(ret, dp[i][j])
print(ret)
