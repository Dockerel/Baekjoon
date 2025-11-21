import sys

input = sys.stdin.readline

n, m = map(int, input().split())

tree = [0] * (n + 1)


def update(index, value):
    global tree
    while index < len(tree):
        tree[index] += value
        index += index & -index


def _sum(index):
    temp = 0
    while index > 0:
        temp += tree[index]
        index -= index & -index
    return temp


ret = []
for _ in range(m):
    cmd, n1, n2 = map(int, input().split())
    if cmd == 0:  # sum
        if n1 > n2:
            n1, n2 = n2, n1
        ret.append(_sum(n2) - _sum(n1 - 1))
    else:  # modify
        temp = _sum(n1) - _sum(n1 - 1)
        update(n1, n2 - temp)

print(*ret, sep="\n")
