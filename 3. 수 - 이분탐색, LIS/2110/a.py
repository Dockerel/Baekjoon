import sys

input = sys.stdin.readline

n, c = list(map(int, input().split()))

x = sorted([int(input()) for _ in range(n)])

start = 1
end = x[-1] - x[0]

ret = -1


def validDist(dist):
    cnt = 1
    prev = x[0]

    for i in range(1, len(x)):
        if x[i] - prev >= dist:
            cnt += 1
            prev = x[i]

    if cnt >= c:
        return True
    return False


while start <= end:

    mid = (start + end) // 2

    if validDist(mid):
        ret = max(ret, mid)
        start = mid + 1
    else:
        end = mid - 1

print(ret)
