import sys
from collections import deque

input = sys.stdin.readline
s, t = input().strip(), input().strip()

for _ in range(len(t) - len(s)):
    if t[-1] == "A":
        t = t[:-1]
    else:
        t = t[:-1][::-1]

print(1 if s == t else 0)
