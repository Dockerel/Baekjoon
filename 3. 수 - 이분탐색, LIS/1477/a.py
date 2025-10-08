import sys

input = sys.stdin.readline

n, m, l = map(int, input().split())
arr = [0, l] + ([] if n == 0 else list(map(int, input().split())))
arr.sort()

gaps = [arr[i] - arr[i - 1] for i in range(1, len(arr))]


def needed(x):
    s = 0
    for d in gaps:
        if d > x:
            s += (d - 1) // x
    return s


lo, hi = 1, l
ret = hi
while lo <= hi:
    mid = (lo + hi) // 2
    if needed(mid) <= m:
        ret = mid
        hi = mid - 1
    else:
        lo = mid + 1

print(ret)
