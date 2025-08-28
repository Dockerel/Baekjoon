import sys

sys.setrecursionlimit(10**6)

input = sys.stdin.readline

n = int(input())
forest = [list(map(int, input().split())) for _ in range(n)]
visited = [[-1] * n for _ in range(n)]  # 이동을 마친 후 이동한 칸 합을 저장

dy = [1, -1, 0, 0]
dx = [0, 0, 1, -1]


def go(y, x):

    global visited

    if visited[y][x] != -1:
        return visited[y][x]

    maxMove = 0
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if ny < 0 or ny >= n or nx < 0 or nx >= n:
            continue
        if forest[y][x] < forest[ny][nx]:
            maxMove = max(maxMove, go(ny, nx) + 1)

    visited[y][x] = maxMove
    return visited[y][x]


for i in range(n):
    for j in range(n):
        if visited[i][j] == -1:
            go(i, j)

ret = -1
for i in range(n):
    for j in range(n):
        ret = max(ret, visited[i][j])
print(ret + 1)
