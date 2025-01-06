import sys
from itertools import combinations as comb

input = sys.stdin.readline

a = [[]]

n, m = list(map(int, input().split()))
for i in range(n):
    l1 = list(map(int, input().split()))
    a.append(l1)

combs = list(comb([i for i in range(1, m + 1)], 3))

ret = -1

for c in combs:
    # 해당 조합의 값 구하기
    _sum = 0
    for i in range(1, n + 1):
        temp = []
        for num in c:
            temp.append(a[i][num - 1])
        _sum += max(temp)
    ret = max(ret, _sum)

print(ret)
