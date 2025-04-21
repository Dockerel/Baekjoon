import sys, math

input = sys.stdin.readline

a, b = list(map(int, input().split()))

for _ in range(math.gcd(a, b)):
    print("1", end="")
