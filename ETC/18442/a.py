import sys
from itertools import combinations as comb

input = sys.stdin.readline

v, p, l = map(int, input().split())

vils = list(map(int, input().split()))

vil_combs = list(comb(vils, p))

ret_sum = sys.maxsize
ret_vils = None


def calc(vil_comb):
    ret_dist = 0
    for vil in vils:
        min_dist = sys.maxsize
        for postal in vil_comb:
            dist = min(abs(postal - vil), l - abs(postal - vil))
            if dist < min_dist:
                min_dist = dist
        ret_dist += min_dist
    return ret_dist


for vil_comb in vil_combs:
    ret = calc(vil_comb)
    if ret < ret_sum:
        ret_sum = ret
        ret_vils = vil_comb

print(ret_sum)
print(*ret_vils)
