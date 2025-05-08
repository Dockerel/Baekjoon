import sys
from collections import deque

input = sys.stdin.readline

f, s, g, u, d = list(map(int, input().split()))  # s -> g
v = [None] * (f + 1)
q = deque()
q.append(s)
v[s] = 0
while q:
    curr = q.popleft()
    up, down = curr + u, curr - d
    if up <= f and up > 0 and v[up] == None:
        v[up] = v[curr] + 1
        q.append(up)
    if down <= f and down > 0 and v[down] == None:
        v[down] = v[curr] + 1
        q.append(down)

print(v[g] if v[g] != None else "use the stairs")
