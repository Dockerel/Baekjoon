import sys

input = sys.stdin.readline

board = [[int(c) for c in input().strip()] for _ in range(8)]

visited = [[0] * 7 for _ in range(8)]

dominos = {}
for i in range(0, 7):
    for j in range(i, 7):
        dominos[(i, j)] = 0

ret = 0


def go(y, x):

    global visited, dominos, ret

    while visited[y][x]:
        y, x = y, x + 1
        if x == 7:
            y, x = y + 1, 0
        if y == 8:
            ret += 1
            return
    visited[y][x] = 1

    for dy, dx in ((1, 0), (0, 1)):
        ny = y + dy
        nx = x + dx
        if ny >= 8 or nx >= 7 or visited[ny][nx]:
            continue

        temp = tuple(sorted([board[y][x], board[ny][nx]]))
        if dominos[temp]:
            continue

        visited[ny][nx] = dominos[temp] = 1
        go(y, x)
        visited[ny][nx] = dominos[temp] = 0

    visited[y][x] = 0


go(0, 0)

print(ret)
