import sys

sys.setrecursionlimit(1000000)

input = sys.stdin.readline

s = input().strip()
n = len(s)

# dp[i][j] : i~j 까지가 팰린드롬
dp = [[-1] * (n) for _ in range(n)]

for i in range(n):
    dp[i][i] = 1


def go(start, end):
    global dp

    if dp[start][end] >= 0:
        return dp[start][end]

    # s[start]==s[end] and dp[start+1][end-1]==1 이면 팰린드롬
    if start > end:
        return 1
    dp[start][end] = 1
    if s[start] != s[end]:
        dp[start][end] = 0
    if go(start + 1, end - 1) == 0:
        dp[start][end] = 0
    return dp[start][end]


for i in range(n):
    for j in range(n):
        if i == j:
            continue
        if i < j and dp[i][j] == -1:
            dp[i][j] = go(i, j)

# dp[i][j] : i~j 까지가 팰린드롬인지

dp2 = [float("inf")] * n


def go2(curr):
    global dp2
    if curr == n:
        return 0
    if dp2[curr] != float("inf"):
        return dp2[curr]
    for i in range(curr, n):
        if dp[curr][i] == 1:
            dp2[curr] = min(dp2[curr], go2(i + 1) + 1)
    return dp2[curr]


print(go2(0))
