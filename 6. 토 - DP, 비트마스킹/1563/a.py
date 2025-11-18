import sys

sys.setrecursionlimit(1000000)

n = int(input())

# 1. 지각을 두 번 이상
# 2. 결석을 세 번 연속
# O: 출석, L: 지각, A: 결석

dp = [[[-1] * 3 for _ in range(2)] for _ in range(n + 1)]


def go(day, late, absent):
    if late == 2 or absent == 3:
        return 0
    if day > n:
        return 1

    if dp[day][late][absent] != -1:
        return dp[day][late][absent]

    dp[day][late][absent] = (
        go(day + 1, late, 0) + go(day + 1, late + 1, 0) + go(day + 1, late, absent + 1)
    ) % 1_000_000
    return dp[day][late][absent]


print(go(1, 0, 0))
