data = [3, 4, 10, 11]
n = len(data)
tree = [0] * (n + 1)


def update(index, value):
    global tree
    while index < len(tree):
        tree[index] += value
        index += index & -index


def _sum(index):
    ret = 0
    while index > 0:
        ret += tree[index]
        index -= index & -index
    return ret


def rangeQuery(left, right):
    return _sum(right) - _sum(left - 1)


for i in range(n):
    update(i + 1, data[i])

print(rangeQuery(1, 2))
print(rangeQuery(2, 4))

update(2, 5)

print(rangeQuery(1, 2))
print(rangeQuery(2, 4))
