import sys

input = sys.stdin.readline


lans = []
k, n = list(map(int, input().rstrip().split()))
global _max
_max = -1


def go(start, end):
    global _max
    length = (start + end) // 2

    if start == length:
        _sum = 0
        for lan in lans:
            _sum += lan // (length + 1)
        if _sum >= n:
            _max = max(_max, length + 1)
        print(_max)
        exit(0)

    _sum = 0
    for lan in lans:
        _sum += lan // length
    if _sum >= n:
        _max = max(_max, length)
        go(length, end)
    elif _sum < n:
        go(start, length)


for _ in range(k):
    num = int(input())
    lans.append(num)

go(0, max(lans))
