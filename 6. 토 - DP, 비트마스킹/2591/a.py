import sys

input = sys.stdin.readline

s = input().strip()

n = len(s)

dp = [-1] * (n + 1)


def go(curr):

    if curr == n:
        return 1

    if dp[curr] != -1:
        return dp[curr]

    cnt = 0

    # 한 자리
    if s[curr] != "0":  # 0은 불가
        cnt += go(curr + 1)

    # 두 자리
    if curr + 1 < n:
        temp = int(s[curr : curr + 2])
        if 10 <= temp <= 34:
            cnt += go(curr + 2)

    dp[curr] = cnt
    return dp[curr]


print(go(0))
