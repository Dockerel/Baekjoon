import sys

input = sys.stdin.readline

n, m = map(int, input().split())
fuels = [list(map(int, input().split())) for _ in range(n)]

dp = [[[float("inf")] * 3 for _ in range(m)] for _ in range(n)]

for j in range(m):
    for k in range(3):
        dp[0][j][k] = fuels[0][j]

dirs = [1, 0, -1]

for i in range(n - 1):
    for j in range(m):
        for k in range(3):
            if dp[i][j][k] == float("inf"):
                continue

            # k 방향 제외한 방향으로 이동
            for d in range(3):
                if d == k:
                    continue

                next_j = j + dirs[d]
                if 0 <= next_j < m:
                    dp[i + 1][next_j][d] = min(
                        dp[i + 1][next_j][d], dp[i][j][k] + fuels[i + 1][next_j]
                    )

ret = float("inf")
for j in range(m):
    for k in range(3):
        ret = min(ret, dp[n - 1][j][k])

print(ret)
