import sys

input = sys.stdin.readline
global n, curr, ret
n = int(input())
curr = 0
ret = 0
global board
board = [0] * 230

#  0   1   2   3   4   5
#  6   7   8   9  10  11
# 12  13 {14} 15  16  17
# 18  19  20  21  22  23
# 24  25  26  27  28  29
# 30  31  32  33  34  35

# n = 4
#  0  1  2  3
#  4  5  6  7
#  8  9 10 11
# 12 13 14 15


def mark(idx, type):
    global board, n

    # 12
    for i in range(idx, -1, -n):
        board[i] = type

    # 3+9
    st = (idx // n) * n
    for i in range(st, st + n):
        board[i] = type

    # 6
    for i in range(idx, n**2, n):
        board[i] = type

    # 1.5
    for i in range(idx, -1, -(n - 1)):
        board[i] = type

    # 4.5
    for i in range(idx, n**2, n + 1):
        board[i] = type

    # 7.5
    for i in range(idx, n**2, n - 1):  # 여기 이상함
        board[i] = type

    # 10.5
    for i in range(idx, -1, -(n + 1)):
        board[i] = type


def go(idx):
    global n, curr, ret
    if curr == n:
        ret += 1
        return
    for i in range(idx, n**2):
        if board[i] == 0:
            curr += 1
            mark(i, 1)
            go(i + 1)
            mark(i, 0)
            curr -= 1


if n == 1:
    print(1)
elif n <= 3:
    print(0)
else:
    go(0)
    print(ret)

1, 1, 1, 1,
1, 1, 1, 0,
1, 1, 1, 0,
1, 0, 0, 1
