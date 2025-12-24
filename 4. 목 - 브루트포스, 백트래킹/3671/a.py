import sys
from itertools import permutations as perm

input = sys.stdin.readline


primes = {0: False, 1: False, 2: True}


def isPrime(n):

    global primes

    if primes.get(n) is not None:
        return primes[n]

    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            primes[n] = False
            return False
    primes[n] = True
    return True


ret = []
for _ in range(int(input())):
    nums = [c for c in input().strip()]
    visited = set()
    count = 0
    for i in range(1, len(nums) + 1):
        for p in perm(nums, i):
            temp = int("".join(p))
            if temp not in visited and isPrime(temp):
                visited.add(temp)
                count += 1
    ret.append(count)

print(*ret, sep="\n")
