import sys

input = sys.stdin.readline
n, m, k = [*map(int, input().split())]

global ret
ret = 0
board = [[0] * m for _ in range(n)]
stickers = []

for _ in range(k):
    ri, ci = [*map(int, input().split())]
    tmp = []
    for i in range(ri):
        tmp.append([*map(int, input().split())])
    stickers.append(tmp)


def rotate(arr):
    return list(zip(*arr[::-1]))


def check(y, x, arr):  # (왼쪽 위 y,x) 스티커가 남은 판에 딱 맞는지
    global ret
    r, c = len(sticker), len(sticker[0])
    for i in range(r):
        for j in range(c):
            if arr[i][j] == 1 and board[y + i][x + j] == 1:
                return 0
    # attach
    for i in range(r):
        for j in range(c):
            if sticker[i][j] == 1:
                board[y + i][x + j] = 1
                ret += 1
    return 1


def go(sticker):  # 1: 붙이는데 성공, 0: 실패
    # 스티커가 판보다 큰 경우
    if n - len(sticker) < 0 or m - len(sticker[0]) < 0:
        return 0
    for i in range(0, n - len(sticker) + 1):
        for j in range(0, m - len(sticker[0]) + 1):
            if check(i, j, sticker):
                return 1
    return 0


for sticker in stickers:
    for _ in range(4):
        if go(sticker) == 1:
            break
        sticker = rotate(sticker)

print(ret)
