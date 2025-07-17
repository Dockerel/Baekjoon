n = int(input())


def isGood(curr):
    for i in range(1, len(curr) // 2 + 1):  # size
        for j in range(0, len(curr) - i):
            if curr[j : j + i] == curr[j + i : j + 2 * i]:
                return False
    return True


def go(curr):
    if len(curr) == n:
        print(*curr, sep="")
        exit(0)
    for i in range(1, 3 + 1):
        temp = curr + [i]
        if isGood(temp):
            go(temp)


for i in range(1, 3 + 1):
    go([i])
