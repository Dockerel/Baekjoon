import sys

input = sys.stdin.readline

MAX = 1000000

mem = [0] * (MAX + 4)

for i in range(1, MAX + 1):
    for j in range(i, MAX + 1, i):
        mem[j] += i
    mem[i] += mem[i - 1]

for _ in range(int(input())):
    n = int(input())
    print(mem[n])
