import sys
from collections import defaultdict

input = sys.stdin.readline

target = int(input())

m, n = list(map(int, input().split()))

a = []
for _ in range(m):
    a.append(int(input()))
b = []
for _ in range(n):
    b.append(int(input()))

pizA = defaultdict(int)
pizB = defaultdict(int)

pizA[sum(a)] += 1
for i in range(0, m):
    _sum = 0
    for j in range(0, m - 1):
        _sum += a[(i + j) % m]
        pizA[_sum] += 1

pizB[sum(b)] += 1
for i in range(0, n):
    _sum = 0
    for j in range(0, n - 1):
        _sum += b[(i + j) % n]
        pizB[_sum] += 1

# A로만 + B로만
ret = pizA[target] + pizB[target]
# A, B 둘다
for i in range(1, target):
    ret += pizA[i] * pizB[target - i]

print(ret)
