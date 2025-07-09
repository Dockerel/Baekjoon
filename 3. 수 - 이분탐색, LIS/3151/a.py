import sys, bisect

input = sys.stdin.readline

n = int(input())
a = sorted(list(map(int, input().split())))

_set = set(a)

ret = 0
for i in range(n - 2):
    for j in range(i + 1, n - 1):
        target = -(a[i] + a[j])
        if target in _set:
            lower_bound = bisect.bisect_left(a, target, j + 1)
            upper_bound = bisect.bisect_right(a, target, j + 1)
            ret += upper_bound - lower_bound

print(ret)
