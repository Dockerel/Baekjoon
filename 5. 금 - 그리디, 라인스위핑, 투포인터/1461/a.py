import sys
from collections import deque

input = sys.stdin.readline

n, m = map(int, input().split())
locs = list(map(int, input().split()))

pos = []
neg = []
for loc in locs:
    pos.append(loc) if loc > 0 else neg.append(-loc)

pos.sort(reverse=True)
neg.sort(reverse=True)

count = []

for i in range(len(pos) // m):
    count.append(pos[i * m])
if len(pos) % m > 0:
    count.append(pos[(len(pos) // m) * m])

for i in range(len(neg) // m):
    count.append(neg[i * m])
if len(neg) % m > 0:
    count.append(neg[(len(neg) // m) * m])

count.sort()
answer = count.pop()
answer += 2 * sum(count)
print(answer)
