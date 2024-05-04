import sys
from itertools import combinations as comb

input = sys.stdin.readline

t = int(input())
for _ in range(t):
    ret = sys.maxsize
    n = int(input())
    _list = list(input().rstrip().split())
    if n <= 32:
        for it in list(comb(_list, 3)):
            temp = [it[0], it[1], it[2]]
            tmp = 0
            for _it in list(comb(temp, 2)):
                for i in range(4):
                    if _it[0][i] != _it[1][i]:
                        tmp += 1
            ret = min(ret, tmp)
        print(ret)
    else:
        print(0)
