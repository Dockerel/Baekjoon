import sys

input = sys.stdin.readline

a, b = map(int, input().split())
b = min(b, 10_000_000)

isPrime = [True] * (b + 1)
isPrime[0] = isPrime[1] = False

i = 2
while i**2 <= b:
    isPrime[i**2 :: i] = [False] * ((b - i**2) // i + 1)
    i += 1


def isPalindrome(n):
    str_n = str(n)
    for i in range(len(str_n) // 2):
        if str_n[i] != str_n[len(str_n) - i - 1]:
            return False
    return True


for i in range(a, b + 1):
    if isPrime[i] and isPalindrome(i):
        print(i)
print(-1)
