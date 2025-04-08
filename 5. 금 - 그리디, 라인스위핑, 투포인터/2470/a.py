import sys

input = sys.stdin.readline

n = int(input())
a = sorted(list(map(int, input().split())))

ret = [sys.maxsize, sys.maxsize]

l, r = 0, n - 1
while l < r:
    temp = a[l] + a[r]
    if abs(temp) < abs(sum(ret)):
        ret = [a[l], a[r]]
    if temp < 0:
        l += 1
    else:
        r -= 1
print(*sorted(ret))
