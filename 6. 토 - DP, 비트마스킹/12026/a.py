import sys

input = sys.stdin.readline
n = int(input())
s = input().strip()

dp = [0] * n

if s[0] != "B":
    print(-1)
    exit(0)


def getNextChar(c):
    if c == "B":
        return "O"
    elif c == "O":
        return "J"
    else:
        return "B"


for i in range(n - 1):
    if i != 0 and dp[i] == 0:
        continue
    nextChar = getNextChar(s[i])
    for j in range(i + 1, n):
        if s[j] != nextChar:
            continue
        if dp[j] == 0:
            dp[j] = dp[i] + (j - i) ** 2
            continue
        dp[j] = min(dp[j], dp[i] + (j - i) ** 2)

print(dp[n - 1] if dp[n - 1] else -1)
