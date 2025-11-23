import sys

input = sys.stdin.readline


def oneToNXOR(n):
    return [n, 1, n + 1, 0][n % 4]


s, f = map(int, input().split())

print(oneToNXOR(f) ^ oneToNXOR(s - 1))
