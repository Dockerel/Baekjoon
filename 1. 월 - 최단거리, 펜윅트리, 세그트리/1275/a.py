import sys

input = sys.stdin.readline

n, q = map(int, input().split())
nums = list(map(int, input().split()))

tree = [0] * (n + 1)


def update(index, value):
    global tree
    while index < len(tree):
        tree[index] += value
        index += index & -index


for i in range(n):
    update(i + 1, nums[i])


def _sum(index):
    ret = 0
    while index > 0:
        ret += tree[index]
        index -= index & -index
    return ret


ret = []
for _ in range(q):
    x, y, a, b = map(int, input().split())
    if y < x:
        x, y = y, x
    # x~y의 합
    ret.append(_sum(y) - _sum(x - 1))

    # a번째 수를 b로 바꾸기
    prev = nums[a - 1]
    nums[a - 1] = b
    update(a, -prev)
    update(a, b)

print(*ret, sep="\n")
