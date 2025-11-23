import sys

input = sys.stdin.readline


def oneToNXOR(n):
    return [n, 1, n + 1, 0][n % 4]


ret = []
for _ in range(int(input())):
    s, f = map(int, input().split())
    if s == f:
        ret.append(s)
        continue
    ret.append(oneToNXOR(f) ^ oneToNXOR(s - 1))

print(*ret, sep="\n")
