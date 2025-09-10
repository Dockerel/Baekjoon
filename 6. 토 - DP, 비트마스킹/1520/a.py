import sys

input = sys.stdin.readline

m, n = list(map(int, input().split()))
a = [[0] * n for _ in range(m)]
dp = [[-1] * n for _ in range(m)]
dy = [0, 1, 0, -1]
dx = [1, 0, -1, 0]

for i in range(m):
    a[i] = list(map(int, input().split()))


def dfs(y, x):
    if y == m - 1 and x == n - 1:
        return 1
    if dp[y][x] != -1:
        return dp[y][x]

    dp[y][x] = 0
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if ny < 0 or ny >= m or nx < 0 or nx >= n:
            continue
        if a[ny][nx] < a[y][x]:
            dp[y][x] += dfs(ny, nx)

    return dp[y][x]


print(dfs(0, 0))
