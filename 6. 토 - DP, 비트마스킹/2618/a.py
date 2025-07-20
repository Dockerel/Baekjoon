import sys

sys.setrecursionlimit(1004)

input = sys.stdin.readline

n = int(input())
w = int(input())

events = [(1, 1), (n, n)]
for _ in range(w):
    x, y = map(int, input().split())
    events.append((x, y))

dp = [[0] * 1004 for _ in range(1004)]


def dist(a, b):
    return abs(events[a][0] - events[b][0]) + abs(events[a][1] - events[b][1])


def go(a, b):
    global dp
    if a == w + 1 or b == w + 1:
        return 0
    if dp[a][b]:
        return dp[a][b]
    next = max(a, b) + 1
    dp[a][b] = min(go(a, next) + dist(b, next), go(next, b) + dist(a, next))
    return dp[a][b]


print(go(0, 1))

a, b = 0, 1
for i in range(2, w + 2):
    if dp[a][i] + dist(b, i) < dp[i][b] + dist(a, i):
        print(2)
        b = i
    else:
        print(1)
        a = i
