import sys

input = sys.stdin.readline

n = int(input())

a = [0, 0, 1, 1, 3]

for i in range(5, n + 1):
    a.append((a[-1] + a[-2] * 2) % 1000000007)

print(a[n])
