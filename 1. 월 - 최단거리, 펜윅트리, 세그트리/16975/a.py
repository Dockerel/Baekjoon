import sys

input = sys.stdin.readline

n = int(input())
a = [0] + list(map(int, input().split()))

tree = [0] * (n + 1)


def update(index, value):
    global tree
    while index < len(tree):
        tree[index] += value
        index += index & -index


def query(index):
    ret = 0
    while index > 0:
        ret += tree[index]
        index -= index & -index
    return ret


for i in range(1, n + 1):
    update(i, a[i] - a[i - 1])

for _ in range(int(input())):
    temp = list(map(int, input().split()))
    cmd = temp[0]
    if cmd == 1:
        left, right, value = temp[1:]
        update(left, value)
        update(right + 1, -value)
    else:
        index = temp[1]
        print(query(index))
