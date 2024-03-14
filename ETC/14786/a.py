import sys
from decimal import *

PI2 = Decimal("3.1415926535897932384626")


def sin(x):
    if x > PI2:
        x %= PI2

    getcontext().prec += 2
    i, lasts, s, fact, num, sign = 1, 0, x, 1, x, 1
    while s != lasts:
        lasts = s
        i += 2
        fact *= i * (i - 1)
        num *= x * x
        sign *= -1
        s += num / fact * sign
    getcontext().prec -= 2
    return +s


input = sys.stdin.readline
A, B, C = map(Decimal, map(int, input().split()))

PI2 *= 2

left = (C - B) / A
right = (C + B) / A

while right - left > Decimal(1e-9):
    x = (left + right) / 2
    tmp = A * x + B * Decimal(sin(x))
    if tmp < C:
        left = x
    else:
        right = x
print((left + right) / 2)
