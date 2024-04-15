import sys

input = sys.stdin.readline
h, m, s = list(map(int, input().rstrip().split()))
t = int(input())

_h = t // 3600
t %= 3600
_m = t // 60
t %= 60
_s = t

carry = 0

s += _s
if s >= 60:
    carry = s // 60
    s %= 60

m += _m + carry
if m >= 60:
    carry = m // 60
    m %= 60

h += _h + carry
if h >= 24:
    h %= 24

print(f"{h} {m} {s}")
