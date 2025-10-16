import sys

input = sys.stdin.readline

n, m = map(int, input().split())
a = list(map(int, input().split()))

left, right = 0, max(a)


def go(mid):
    cnt = 1
    i = 0
    _min = float("inf")
    _max = -float("inf")
    while i < n:
        _min = min(_min, a[i])
        _max = max(_max, a[i])
        if _max - _min > mid:
            cnt += 1
            _min = float("inf")
            _max = -float("inf")
            i -= 1
        i += 1
    return cnt


while left < right:
    mid = (left + right) // 2
    if go(mid) <= m:
        right = mid
    else:
        left = mid + 1

print(right)
