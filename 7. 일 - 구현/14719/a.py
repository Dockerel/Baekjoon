import sys

input = sys.stdin.readline

h, w = map(int, input().split())
a = list(map(int, input().split()))

ret = 0

for i in range(1, w - 1):
    left = max(a[:i])
    right = max(a[i + 1 :])
    min_h = min(left, right)
    if min_h > a[i]:
        ret += min_h - a[i]

print(ret)
