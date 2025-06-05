import sys
from itertools import combinations as comb

input = sys.stdin.readline
n = int(input())
a = list(map(int, input().split()))

ret = set()
for i in range(1, n + 1):
    for c in list(comb(range(n), i)):
        _sum = 0
        for idx in c:
            _sum += a[idx]
        ret.add(_sum)

curr = 0
for num in sorted(ret):
    next = curr + 1
    if next < num:
        print(next)
        exit(0)
    curr += 1
print(curr + 1)
