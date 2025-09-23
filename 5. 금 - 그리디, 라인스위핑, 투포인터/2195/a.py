import sys

input = sys.stdin.readline

s = input().strip()
p = input().strip()

ret = 0
start = 0

while start < len(p):
    end = start + 1
    max_len = -1
    while end <= len(p):
        temp = p[start:end]
        if temp in s:
            end += 1
            max_len = len(temp)
            continue
        break
    ret += 1
    start += max_len

print(ret)
