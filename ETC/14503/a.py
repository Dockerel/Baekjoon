import sys
from collections import deque

ans = 0

input = sys.stdin.readline

n, m = list(map(int, input().split()))
r, c, d = list(map(int, input().split()))

a = []
for _ in range(n):
    a.append(list(map(int, input().split())))

dy = [-1, 0, 1, 0]
dx = [0, 1, 0, -1]


def rotate(dr):
    dr -= 1
    if dr < 0:
        return 3
    return dr


def check(y, x):
    for i in range(0, 4):
        ny = y + dy[i]
        nx = x + dx[i]
        if a[ny][nx] == 0:
            return 1
    return 0


y, x, dr = r, c, d
while 1:
    if a[y][x] == 0:
        a[y][x] = 1
        ans += 1
    try:
        if check(y, x):
            while 1:
                dr = rotate(dr)
                ny = dy[dr] + y
                nx = dx[dr] + x
                try:
                    if a[ny][nx] == 1:
                        y, x = ny, nx
                        break
                except IndexError:
                    continue
        else:
            ny = y - dy[dr]
            nx = x - dx[dr]
            try:
                if a[ny][nx] == 1:
                    y, x = ny, nx
                else:
                    break
            except IndexError:
                continue
    except IndexError:
        continue

print(ans)
