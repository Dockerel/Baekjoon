import sys

input = sys.stdin.readline
n = int(input())
k = int(input())
a = sorted(list(map(int, input().split())))
d = []
for i in range(1, n):
    d.append(a[i] - a[i - 1])
d = sorted(d)
for _ in range(k - 1):
    try:
        d.pop()
    except:
        break
print(sum(d))
