import sys

input = sys.stdin.readline

n, d, k, c = list(map(int, input().split()))
plates = [int(input()) for _ in range(n)]

ret = 0

for i in range(k, len(plates) + 1):
    temp = set(plates[i - k : i])
    tempLen = len(temp)
    if c not in temp:
        tempLen += 1
    ret = max(ret, tempLen)

for i in range(1, k):
    temp = set(plates[:i] + plates[-abs(k - i) :])
    tempLen = len(temp)
    if c not in temp:
        tempLen += 1
    ret = max(ret, tempLen)

print(ret)
