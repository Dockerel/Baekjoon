import sys

input = sys.stdin.readline
n, m, k = [*map(int, input().split())]

_list, _size = [], []

for _ in range(k):
    ri, ci = [*map(int, input().split())]
    _size.append([ri, ci])
    tmp = []
    for i in range(ri):
        tmp.append([*map(int, input().split())])
    _list.append(tmp)


def rotate(l1):
    return list(zip(*l1[::-1]))


def fit(rr, cc, y, x, l1):  # (왼쪽 위 y,x) 스티커가 남은 판에 딱 맞는지
    pass


def attach(i):
    pass


for i in range(k):
    attach(i)
