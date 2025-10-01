import sys
from collections import deque

input = sys.stdin.readline

n, k = map(int, input().split())

maps = [[int(c) for c in input().strip()] for _ in range(2)]

# (왼/오, 현재 칸:n-1에 도달하면 승리, 현재 시간:-1부터 시작. 가는 칸이 현재 시간보다 무조건 커야 함)

v = [[0] * n for _ in range(2)]
v[0][0] = 1

q = deque()
q.append((0, 0, 0))
while q:
    leftOrRight, curr, currT = q.popleft()
    if curr + 1 >= n or curr + k >= n:
        print(1)
        exit(0)
    # 한 칸 앞
    if (
        curr + 1 < n
        and v[leftOrRight][curr + 1] == 0
        and maps[leftOrRight][curr + 1] == 1
    ):
        v[leftOrRight][curr + 1] = 1
        q.append((leftOrRight, curr + 1, currT + 1))
    # 한 칸 뒤
    if (
        curr - 1 < n
        and curr - 1 > currT
        and v[leftOrRight][curr - 1] == 0
        and maps[leftOrRight][curr - 1] == 1
    ):
        v[leftOrRight][curr - 1] = 1
        q.append((leftOrRight, curr - 1, currT + 1))
    # 반대편 줄로 점프
    if (
        curr + k < n
        and v[leftOrRight ^ 1][curr + k] == 0
        and maps[leftOrRight ^ 1][curr + k] == 1
    ):
        v[leftOrRight ^ 1][curr + k] = 1
        q.append((leftOrRight ^ 1, curr + k, currT + 1))

print(0)
