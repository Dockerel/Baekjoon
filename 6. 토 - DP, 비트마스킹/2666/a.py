import sys

input = sys.stdin.readline

n = int(input())
open = list(map(int, input().split()))
useLen = int(input())
use = [int(input()) for _ in range(useLen)]

dp = [[[0] * 24 for _ in range(24)] for _ in range(24)]


def go(curr, door1, door2):
    if curr == useLen:
        return 0
    if dp[curr][door1][door2]:
        return dp[curr][door1][door2]
    currUse = use[curr]
    use_left = abs(currUse - door1) + go(curr + 1, currUse, door2)
    use_right = abs(currUse - door2) + go(curr + 1, door1, currUse)
    dp[curr][door1][door2] = min(use_left, use_right)
    return dp[curr][door1][door2]


print(go(0, *open))
