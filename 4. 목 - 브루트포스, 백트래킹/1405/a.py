import sys

input = sys.stdin.readline

move, e, w, s, n = map(int, input().split())

e /= 100
w /= 100
s /= 100
n /= 100

visited = [[0] * (2 * move + 4) for _ in range(2 * move + 4)]


ret = 0

dy = [1, -1, 0, 0]
dx = [0, 0, 1, -1]
p = [s, n, e, w]


def go(y, x, move_cnt, probability):

    global ret

    if move_cnt == move:
        ret += probability
        return

    visited[y][x] = 1
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if visited[ny][nx] == 0:
            go(ny, nx, move_cnt + 1, probability * p[i])
            visited[ny][nx] = 0


go(move, move, 0, 1)  # y,x,move_cnt

print(ret)
