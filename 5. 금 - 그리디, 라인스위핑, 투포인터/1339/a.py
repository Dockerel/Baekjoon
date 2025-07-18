import sys
from itertools import permutations as perm

input = sys.stdin.readline

chars = {}

for _ in range(int(input())):
    word = input().strip()
    for i in range(0, len(word)):
        c = word[i]
        if chars.get(c) == None:
            chars[c] = 0
        chars[c] += 10 ** (len(word) - i - 1)

nums = sorted(chars.values(), reverse=True)
mult = list(range(9, 9 - len(chars), -1))

ret = 0
for i in range(len(nums)):
    ret += nums[i] * mult[i]

print(ret)
