import sys

input = sys.stdin.readline
d, k = map(int, input().split())
tteok = [(1, 0), (0, 1)]
for _ in range(d - 2):
    prv = tteok[-1]
    pprv = tteok[-2]
    tteok.append((prv[0] + pprv[0], prv[1] + pprv[1]))
tteok = tteok[-1]
i = 1
while 1:
    temp = k - tteok[0] * i
    if temp % tteok[1] == 0:
        n1, n2 = i, temp // tteok[1]
        print(f"{min(n1,n2)}\n{max(n1,n2)}")
        break
    i += 1
