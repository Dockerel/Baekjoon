import sys

input = sys.stdin.readline

n = int(input())
a = [list(map(int, input().split())) for _ in range(n)]

v = [[0] * n for _ in range(n)]
v[0][0] = 1

for i in range(n):
    for j in range(n):
        if v[i][j] == 0:
            continue
        val = a[i][j]
        if i + val < n:
            v[i + val][j] = 1
        if j + val < n:
            v[i][j + val] = 1

print("HaruHaru" if v[n - 1][n - 1] else "Hing")
