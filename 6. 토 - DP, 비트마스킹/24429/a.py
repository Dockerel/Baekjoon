import sys

input = sys.stdin.readline

n = int(input())
scores = [list(map(int, input().split())) for _ in range(n)]

p = int(input())
rcs = [[1, 1]] + [list(map(int, input().split())) for _ in range(p)] + [[n, n]]

rcs = sorted(rcs)

for i in range(1, p + 2):
    fromR = rcs[i - 1][0] - 1
    fromC = rcs[i - 1][1] - 1
    toR = rcs[i][0] - 1
    toC = rcs[i][1] - 1

    if fromR > toR or fromC > toC:
        print(-1)
        exit(0)

dp = [[float("-inf")] * n for _ in range(n)]
dp[0][0] = scores[0][0]

for i in range(1, p + 2):
    fromR = rcs[i - 1][0] - 1
    fromC = rcs[i - 1][1] - 1
    toR = rcs[i][0] - 1
    toC = rcs[i][1] - 1

    for r in range(fromR, toR + 1):
        for c in range(fromC, toC + 1):
            if r == fromR and c == fromC:
                continue

            current_max = float("-inf")

            if r > fromR and dp[r - 1][c] != float("-inf"):
                current_max = max(current_max, dp[r - 1][c])

            if c > fromC and dp[r][c - 1] != float("-inf"):
                current_max = max(current_max, dp[r][c - 1])

            if current_max != float("-inf"):
                dp[r][c] = current_max + scores[r][c]

print(dp[n - 1][n - 1])
