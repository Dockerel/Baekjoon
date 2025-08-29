import sys

input = sys.stdin.readline

n, m = map(int, input().split())

points = [list(map(int, input().split())) for _ in range(n)]

max_val = -1
for point in points:
    max_val = max(max_val, max(point))

candies = [[0] * (max_val + 1) for _ in range(max_val + 1)]
dp = [
    [-1] * (max_val + 1) for _ in range(max_val + 1)
]  # 해당 위치에서 먹을 수 있는 사탕의 최대 수

for x, y in points:
    candies[y][x] = m
dp[0][0] = 0

dy = [1, 0]
dx = [0, 1]


def go(y, x, curr_time, curr_candies):
    temp = candies[y][x] - curr_time
    temp = temp if temp > 0 else 0

    temp += curr_candies

    if dp[y][x] >= temp:
        return

    dp[y][x] = temp

    for i in range(2):
        ny = y + dy[i]
        nx = x + dx[i]
        if ny < 0 or nx < 0 or ny > max_val or nx > max_val:
            continue
        go(ny, nx, curr_time + 1, temp)


go(1, 0, 1, 0)
go(0, 1, 1, 0)

ret = -1
for i in range(max_val + 1):
    for j in range(max_val + 1):
        ret = max(ret, dp[i][j])
print(ret)
