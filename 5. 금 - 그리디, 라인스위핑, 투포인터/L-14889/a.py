import sys
from itertools import combinations as comb

input = sys.stdin.readline

n = int(input())

a = []

for i in range(n):
    a.append(list(map(int, input().split())))

d = {}

for c in list(comb(range(n), n // 2)):
    d[c] = 1


def oppositeTeam(t):
    ret = []
    for i in range(n):
        if i not in t:
            ret.append(i)
    return ret


def getTeamVal(t):
    ret = 0
    for c in list(comb(range(len(t)), 2)):
        ret += a[t[c[0]]][t[c[1]]]
        ret += a[t[c[1]]][t[c[0]]]
    return ret


ret = sys.maxsize
for k in d.keys():
    t1 = list(k)
    t2 = oppositeTeam(t1)

    val1 = getTeamVal(t1)
    val2 = getTeamVal(t2)

    ret = min(ret, abs(val1 - val2))

print(ret)
