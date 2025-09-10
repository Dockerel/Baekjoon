from itertools import combinations as comb
import sys

ret = 0


def weightComb(list1):
    result = []
    for i in range(0, len(list1) + 1):
        for sub in comb(list1, i):
            result.append(sum(sub))
    return sorted(result)


n, c = map(int, input().split())
l = list(map(int, sys.stdin.readline().split()))

ll = l[: len(l) // 2]
lr = l[len(l) // 2 :]

cll = weightComb(ll)
clr = weightComb(lr)


for right in clr:
    if right > c:
        break
    for left in cll:
        if right + left > c:
            break
        else:
            ret += 1

print(ret)
