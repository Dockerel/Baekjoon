import sys, heapq

input = sys.stdin.readline

n, m = map(int, input().split())

a = list(map(int, input().split()))
b = list(map(int, input().split()))

pq = []
for i in range(m):
    plus_score = min(b[i], 100 - a[i])
    if plus_score == 0:
        continue
    pq.append((-plus_score, i))
heapq.heapify(pq)

for _ in range(24 * n):
    if not pq:
        break
    plus_score, idx = heapq.heappop(pq)
    plus_score *= -1
    a[idx] = min(a[idx] + plus_score, 100)
    plus_score = min(plus_score, 100 - a[idx])
    if plus_score == 0:
        continue
    heapq.heappush(pq, (-plus_score, idx))

print(sum(a))
