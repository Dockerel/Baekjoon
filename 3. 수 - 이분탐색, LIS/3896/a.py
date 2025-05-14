import sys, bisect

input = sys.stdin.readline


def findPrimes(n):
    primes = [0, 0] + [1] * (n - 1)
    i = 2
    while i**2 <= n:
        primes[i**2 :: i] = [0] * ((n - i**2) // i + 1)
        i += 1
    return primes


isPrime = findPrimes(1299710)
primes = [i for i in range(1299710 + 1) if isPrime[i]]

for _ in range(int(input())):
    k = int(input())
    if isPrime[k]:
        print(0)
        continue
    loc = bisect.bisect(primes, k)
    print(primes[loc] - primes[loc - 1])
