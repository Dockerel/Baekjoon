import sys

input = sys.stdin.readline

n, k = list(map(int, input().split()))
a = list(map(int, input().split()))

ryans = [i for i in range(n) if a[i] == 1]

if not ryans:
    print(-1)
    exit(0)

ret = -1


start, end = 0, k - 1
while 1:
    if end >= len(ryans):
        break
    ret = min(ret if ret > 0 else sys.maxsize, ryans[end] - ryans[start] + 1)
    start += 1
    end += 1

print(ret)
