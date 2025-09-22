import sys

input = sys.stdin.readline

n, k = map(int, input().split())
hasEnergy = [0] + list(map(int, input().split()))

for i in range(n, 0, -1):
    if hasEnergy[i] == 1:
        hasEnergy[i] = i
    else:
        hasEnergy[i] = hasEnergy[i + 1]


def check(t):
    curr = n
    currTm = k

    while curr > 1 and currTm >= 0:
        if hasEnergy[curr] == curr:
            curr = curr - t
            currTm -= 1
        else:
            curr = hasEnergy[curr]

    return curr <= 1 and currTm >= 0


lo, hi = 1, n
while lo <= hi:
    mid = (lo + hi) // 2
    if check(mid):
        hi = mid - 1
    else:
        lo = mid + 1

print(lo)
