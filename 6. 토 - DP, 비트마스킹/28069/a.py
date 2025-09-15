import sys
from collections import deque

input = sys.stdin.readline

n, k = map(int, input().split())

# 1. 계단 한 칸 올라가기
# 2. i번째 칸에서 i+floor(i/2)로 순간이동
# 현재 0번째 칸에 존재
# k번째 행동에서 n에 도달하면 -> minigimbob
# else -> water

dp = [float("inf")] * (n + 1)
dp[0] = 0

q = deque()
q.append((0, 0))

while q:
    currN, currK = q.popleft()

    if currN + 1 <= n and currK + 1 < dp[currN + 1]:
        dp[currN + 1] = currK + 1
        q.append((currN + 1, currK + 1))

    temp = currN + currN // 2
    if currN != temp and temp <= n and currK + 1 < dp[temp]:
        dp[temp] = currK + 1
        q.append((temp, currK + 1))

print("minigimbob" if dp[n] <= k else "water")
