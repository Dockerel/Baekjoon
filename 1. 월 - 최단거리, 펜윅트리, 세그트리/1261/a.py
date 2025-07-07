import sys
from collections import deque

input = sys.stdin.readline

n, m = map(int, input().split())
maze = [[int(c) for c in input().strip()] for _ in range(m)]

visited = [[float("inf") for _ in range(n)] for _ in range(m)]

q = deque([(0, 0, 0)])

dy = [1, -1, 0, 0]
dx = [0, 0, 1, -1]

while q:
    y, x, wall = q.popleft()
    if wall > visited[y][x]:
        continue
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if ny < 0 or ny >= m or nx < 0 or nx >= n:
            continue
        breakW = 0
        if maze[ny][nx]:
            breakW = 1
        wallSum = wall + breakW
        if wallSum < visited[ny][nx]:
            visited[ny][nx] = wallSum
            q.append((ny, nx, wallSum))

print(0 if visited[m - 1][n - 1] == float("inf") else visited[m - 1][n - 1])
