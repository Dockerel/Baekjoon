import sys

input = sys.stdin.readline

s = input().strip()

ret = set()
for i in range(len(s)):
    curr = ""
    for j in range(i, len(s)):
        curr += s[j]
        ret.add(curr)
print(len(ret))
