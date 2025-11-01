import sys
from collections import deque

input = sys.stdin.readline

n, m, k = map(int, input().split())

a = [[0] * m for _ in range(n)]
for _ in range(k):
    r, c = map(int, input().split())
    a[r - 1][c - 1] = 1

q = deque()

visited = [[0] * m for _ in range(n)]

ret = -1
for i in range(n):
    for j in range(m):
        if a[i][j] == 1 and visited[i][j] == 0:
            temp = 1
            q.append((i, j))
            visited[i][j] = 1
            while q:
                y, x = q.popleft()
                for d in range(4):
                    ny = y + [1, -1, 0, 0][d]
                    nx = x + [0, 0, 1, -1][d]
                    if ny < 0 or ny >= n or nx < 0 or nx >= m:
                        continue
                    if a[ny][nx] == 0 or visited[ny][nx] == 1:
                        continue
                    temp += 1
                    q.append((ny, nx))
                    visited[ny][nx] = 1
            ret = max(ret, temp)

print(ret)
