import sys

input = sys.stdin.readline

n = int(input())
s = input().strip()

# DKSH

dp = [1] + [0] * 4


def charToInt(c):
    return "DKSH".index(c) + 1


for c in s:
    if c not in "DKSH":
        continue
    idx = charToInt(c)
    dp[idx] += dp[idx - 1]

print(dp[-1])
