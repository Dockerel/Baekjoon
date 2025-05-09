import sys

input = sys.stdin.readline

n, m = list(map(int, input().split()))

listA = [[int(c) for c in input().strip()] for _ in range(n)]
listB = [[int(c) for c in input().strip()] for _ in range(n)]

if n < 3 or m < 3:
    print(0 if listA == listB else -1)
    exit(0)


def flip(y, x):
    global listA
    for i in range(y, y + 3):
        for j in range(x, x + 3):
            listA[i][j] = 0 if listA[i][j] else 1


ret = 0
for i in range(n - 2):
    for j in range(m - 2):
        if listA[i][j] != listB[i][j]:
            flip(i, j)
            ret += 1

print(ret if listA == listB else -1)
