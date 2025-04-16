import sys
from math import gcd

input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))

d = {}
for num in a:
    if num not in d:
        d[num] = 0
    d[num] += 1

ret = []

a = sorted(a)

max_val = a[-1]
ret.append(max_val)
d[max_val] -= 1
if d[max_val] == 0:
    del d[max_val]

while len(ret) < n:
    max_val = a[-1]
    while d.get(max_val) == None:
        a.pop()
        max_val = a[-1]

    d[max_val] -= 1
    if d[max_val] == 0:
        del d[max_val]

    for val in ret:
        g = gcd(val, max_val)
        d[g] -= 2
        if d[g] == 0:
            del d[g]

    ret.append(max_val)

print(*ret)
