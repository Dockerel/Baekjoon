# import sys

# input = sys.stdin.readline

# a = list(map(int, input().split()))
# n, m = list(map(int, input().split()))


n = int(input())
if n == 0:
    print("NO")
    exit(0)
while n > 0:
    if n % 3:
        n -= 1
    if n % 3:
        print("NO")
        exit(0)
    n //= 3
print("YES")
