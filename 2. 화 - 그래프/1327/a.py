import sys
from collections import deque

input = sys.stdin.readline

n, k = map(int, input().split())
a = tuple(map(int, input().split()))

visited = set()

q = deque()
q.append((a, 0))
visited.add(a)

while q:
    aa, ret = q.popleft()

    if aa == tuple(range(1, n + 1)):
        print(ret)
        exit(0)

    for i in range(n - k + 1):
        temp = aa[:i] + aa[i : i + k][::-1] + aa[i + k :]
        if temp in visited:
            continue
        q.append((temp, ret + 1))
        visited.add(tuple(temp))

print(-1)
