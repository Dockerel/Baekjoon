import sys
from collections import deque

input = sys.stdin.readline

n, m = map(int, input().split())

a = [[c for c in input().strip()] for _ in range(n)]

v = [[0 for _ in range(m)] for _ in range(n)]

dy = [1, -1, 0, 0]
dx = [0, 0, 1, -1]


def check(i, j):

    global v

    # y, x로 부터 확장 가능한 최대 직사각형
    # 가로 범위, 세로 범위 구해서 확장되는 직사각형이 모두 범위 안에 있는지 검사

    horizontal_range = 0
    while j + horizontal_range < m and a[i][j] == a[i][j + horizontal_range]:
        horizontal_range += 1

    vertical_range = 0
    while i + vertical_range < n and a[i][j] == a[i + vertical_range][j]:
        vertical_range += 1

    q = deque()
    q.append((i, j))
    v[i][j] = 1
    temp = 0
    while q:
        y, x = q.popleft()
        temp += 1
        for d in range(4):
            ny = y + dy[d]
            nx = x + dx[d]
            if (
                ny < 0
                or ny >= n
                or nx < 0
                or nx >= m
                or a[ny][nx] != a[i][j]
                or v[ny][nx]
            ):
                continue
            v[ny][nx] = 1
            q.append((ny, nx))
    if temp != horizontal_range * vertical_range:
        print("BaboBabo")
        exit(0)


for i in range(n):
    for j in range(m):
        if v[i][j]:
            continue
        check(i, j)

print("dd")
