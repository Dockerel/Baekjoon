import sys
from collections import deque

input = sys.stdin.readline


def isPoint(y, x):
    if (y == 0 or y == 4) and (x == 0 or x == 4):
        return True
    return False


visited = [[[0] * 5] * 5] * 5
maze = []
for _ in range(5):
    temp = []
    for i in range(5):
        _list = list(map(int, input().rstrip().split()))
        temp.append(_list)
    maze.append(temp)

ins = []

for i in [0, 4]:
    for j in [0, 4]:
        if maze[0][i][j] and isPoint(i, j):
            ins.append([i, j])

q = deque(ins)
print(q)
