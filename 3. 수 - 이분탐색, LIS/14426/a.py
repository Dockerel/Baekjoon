import sys

input = sys.stdin.readline

n, m = list(map(int, input().split()))

root = {}

for _ in range(n):
    s = input().strip()
    curr = root
    for c in s:
        if curr.get(c) == None:
            curr[c] = {}
        curr = curr[c]

ret = 0
for _ in range(m):
    s = input().strip()
    curr = root
    flag = 1
    for c in s:
        if c in curr:
            curr = curr[c]
        else:
            flag = 0
            break
    if flag:
        ret += 1

print(ret)
