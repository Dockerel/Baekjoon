import sys

input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))

sum_a = [0]
for i in a:
    sum_a.append(sum_a[-1] + i)

for i in range(1, n + 1):
    max_std = -1
    max_idx = 0
    for j in range(n - i + 1):
        mean = (sum_a[j + i] - sum_a[j]) / i
        vsum = 0
        for val in a[j : j + i]:
            vsum += (val - mean) ** 2
        var = vsum / i
        std = round(var**0.5, 9)
        if max_std < std:
            max_std = std
            max_idx = j+1
    print(max_idx)