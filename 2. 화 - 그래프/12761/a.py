import sys
from collections import deque

input = sys.stdin.readline

a, b, n, m = map(int, input().split())

v = [0] * (100000 + 1)
v[n] = 1

q = deque()
q.append((n, 0))

while q:
    curr_loc, curr_time = q.popleft()
    if curr_loc == m:
        print(curr_time)
        break

    if curr_loc + 1 <= 100000 and v[curr_loc + 1] == 0:
        v[curr_loc + 1] = 1
        q.append([curr_loc + 1, curr_time + 1])
    if curr_loc - 1 >= 0 and v[curr_loc - 1] == 0:
        v[curr_loc - 1] = 1
        q.append([curr_loc - 1, curr_time + 1])

    if curr_loc + a <= 100000 and v[curr_loc + a] == 0:
        v[curr_loc + a] = 1
        q.append([curr_loc + a, curr_time + 1])
    if curr_loc + b <= 100000 and v[curr_loc + b] == 0:
        v[curr_loc + b] = 1
        q.append([curr_loc + b, curr_time + 1])

    if curr_loc - a >= 0 and v[curr_loc - a] == 0:
        v[curr_loc - a] = 1
        q.append([curr_loc - a, curr_time + 1])
    if curr_loc - b >= 0 and v[curr_loc - b] == 0:
        v[curr_loc - b] = 1
        q.append([curr_loc - b, curr_time + 1])

    if curr_loc * a <= 100000 and v[curr_loc * a] == 0:
        v[curr_loc * a] = 1
        q.append([curr_loc * a, curr_time + 1])
    if curr_loc * b <= 100000 and v[curr_loc * b] == 0:
        v[curr_loc * b] = 1
        q.append([curr_loc * b, curr_time + 1])
