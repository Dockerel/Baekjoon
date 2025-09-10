import sys
from collections import defaultdict

input = sys.stdin.readline

n = int(input())
a, b, c, d = [], [], [], []

for _ in range(n):
    temp = list(map(int, input().split()))
    a.append(temp[0])
    b.append(temp[1])
    c.append(temp[2])
    d.append(temp[3])

ab_sums = defaultdict(int)
for i in range(n):
    for j in range(n):
        ab_sums[a[i] + b[j]] += 1

result = 0
for i in range(n):
    for j in range(n):
        cd_sum = c[i] + d[j]
        if -cd_sum in ab_sums:
            result += ab_sums[-cd_sum]

print(result)
