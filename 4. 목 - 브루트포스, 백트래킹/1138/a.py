import sys
from itertools import permutations as perm

input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))

for p in perm(range(n)):
    curr = [0] * n
    for i in range(n):
        temp = 0
        for j in range(i):
            if p[i] < p[j]:
                temp += 1
        curr[p[i]] = temp
    if curr == a:
        print(*[i + 1 for i in p])
        break
