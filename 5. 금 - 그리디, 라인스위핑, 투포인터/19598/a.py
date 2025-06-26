import sys, heapq

input = sys.stdin.readline

a = []
pq = []
ret = -1

n = int(input())
for _ in range(n):
    _from, _to = map(int, input().split())
    a.append((_from, _to))

a = sorted(a)
for _from, _to in a:
    if len(pq) == 0:
        heapq.heappush(pq, (_to, _from))
    else:
        temp = heapq.heappop(pq)
        if temp[0] <= _from:
            heapq.heappush(pq, (_to, _from))
        else:
            heapq.heappush(pq, temp)
            heapq.heappush(pq, (_to, _from))
    ret = max(ret, len(pq))

print(ret)
