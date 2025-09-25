import sys

input = sys.stdin.readline

ranges = []

n = int(input())
for _ in range(n):
    frm, to = map(int, input().split())
    ranges.append((frm, to))

ranges.sort()

ret = -1
for i in range(n - 1):
    temp = 0
    curr = ranges[i]
    for j in range(i + 1, n):
        if curr[0] <= ranges[j][0] and ranges[j][1] <= curr[1]:
            temp += 1
    ret = max(ret, temp)

print(ret)
