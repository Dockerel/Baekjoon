import sys

input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))

d = {}
for num in a:
    d[num] = d.get(num, 0) + 1

# (0,3), (1,2):XOR->3
# (1,3), (0,2):XOR->2
# (0,1),(2,3):XOR->1
# 두 수가 같으면:XOR->0

ret = 0
targets = [(0, 3), (1, 2), (1, 3), (0, 2), (0, 1), (2, 3)]
for target in targets:
    while d.get(target[0], 0) and d.get(target[1], 0):
        ret += target[0] ^ target[1]
        d[target[0]] -= 1
        d[target[1]] -= 1

print(ret)
