import sys, heapq

input = sys.stdin.readline

n = int(input())
pq = []
for _ in range(n):
    n1, n2 = sorted(list(map(int, input().split())))
    heapq.heappush(pq, (n1, n2))

ret = 0

currStart = None
currEnd = None
for gap in pq:
    start, end = gap
    if currStart == None:
        currStart, currEnd = start, end
        continue
    # 기존 구간에 포함되는 상황
    if end <= currEnd:
        continue
    # 안겹치는 상황
    if start > currEnd:
        ret += abs(currStart - currEnd)
        currStart, currEnd = start, end
        continue
    # 겹치지만 end가 벗어나는 상황
    if end > currEnd:
        currEnd = end
ret += abs(currStart - currEnd)

print(ret)
