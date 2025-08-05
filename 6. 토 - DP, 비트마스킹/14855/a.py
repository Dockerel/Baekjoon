import sys

input = sys.stdin.readline

n, m, c0, d0 = map(int, input().split())

dp = [-1] * (n + 1)  # dp[사용한 밀가루 양] = 최대 만두 금액 합
dp[0] = 0

for i in range(n // c0):
    mando = i + 1
    dp[c0 * mando] = d0 * mando

for _ in range(m):
    a, b, c, d = map(int, input().split())
    ndp = dp[:]
    for i in range(a // b):
        mando = i + 1
        mandoW = c * mando
        mandoM = d * mando
        for j in range(n, mandoW - 1, -1):
            if dp[j - mandoW] >= 0:
                ndp[j] = max(ndp[j], dp[j - mandoW] + mandoM)
    dp = ndp

print(max(dp))
