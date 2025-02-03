# 휠 세그먼트 소수 체(Wheel Factorization Sieve)

def primes_under(N):
    n = N + 6 - N % 6
    sieve = [True] * (n // 3)
    for i in range(1, int(n ** 0.5) // 3 + 1):
        if sieve[i]:
            k = 1 | 3 * i + 1
            d, s, j = k * 2, k * k, k * (k + 4 - 2 * (i & 1))
            sieve[s // 3::d] = [False] * ((n//6 - s//6 - 1) // k + 1)
            sieve[j // 3::d] = [False] * ((n//6 - j//6 - 1) // k + 1)
    return [2, 3] + [1 | 3 * i + 1 for i in range(1, n // 3 + (N % 6 > 1) - 2) if sieve[i]]