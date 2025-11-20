import sys

input = sys.stdin.readline

n = 100000

# +1 했을 때 해당 위치가 0이었으면 꽃 안피고, 0보다 큰 수였으면 꽃 핌
# F[i] = a[i] - a[i-1]
# 구간 3~5을 +k
# F[3] = a[3] + k - a[2] = a[3] - a[2] + k
# F[4] = a[4] + k - (a[3] + k) = a[4] - a[3]
# F[5] = a[5] + k - (a[4] + k) = a[5] - a[4]
# F[6] = a[6] - (a[5] + k) = a[6] - a[5] -k
# 구간 [A,B]에 대해 F[A]를 k만큼 증가, F[B+1]를 k만큼 감소

# a[C]의 값을 구하려면 F[1]+...+F[C]

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


answer = []

days = int(input())
for _ in range(days):
    l, r = map(int, input().split())
    prevL, prevR = _sum(l), _sum(r)
    flowers = prevL + prevR
    answer.append(flowers)

    update(l, -prevL)
    update(l + 1, prevL)
    update(r, -prevR)
    update(r + 1, prevR)
    update(l + 1, 1)
    update(r, -1)

print(*answer, sep="\n")
