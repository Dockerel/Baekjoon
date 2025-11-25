import sys

input = sys.stdin.readline

n, k = map(int, input().split())

ret = 0
while 1:
    if bin(n).count("1") <= k:
        break
    n += 1
    ret += 1

print(ret)
