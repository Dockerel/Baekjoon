import sys

input = sys.stdin.readline

n, k = list(map(int, input().split()))
wgt, val = [], []
for i in range(n):
    w, v = list(map(int, input().split()))
    wgt.append(w)
    val.append(v)
dp = [[0] * (k + 4) for _ in range(n + 4)]


def go(idx, w):
    if idx == n:
        return 0
    if dp[idx][w] > 0:
        return dp[idx][w]
    v1 = 0
    if w + wgt[idx] <= k:
        v1 = go(idx + 1, w + wgt[idx]) + val[idx]
    dp[idx][w] = max(v1, go(idx + 1, w))
    return dp[idx][w]


print(go(0, 0))
