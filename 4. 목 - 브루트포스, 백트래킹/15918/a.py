import sys

input = sys.stdin.readline

n, x, y = map(int, input().split())

x -= 1
y -= 1

a = [0] * (n * 2)
a[x] = a[y] = y - x - 1

ret = 0


def go(curr):

    global a, ret

    if curr == n + 1:
        ret += 1

    if curr == y - x - 1:
        go(curr + 1)
        return

    for i in range(2 * n - curr - 1):
        if a[i] == 0 and a[i + curr + 1] == 0:
            a[i] = a[i + curr + 1] = curr
            go(curr + 1)
            a[i] = a[i + curr + 1] = 0


go(1)

print(ret)
