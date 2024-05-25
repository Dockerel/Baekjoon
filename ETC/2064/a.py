import sys

input = sys.stdin.readline

n = int(input())


def convertAddr(addr):
    temp = ""
    for num in addr:
        temp += format(num, "08b")
    return int(temp, 2)


addrs = [convertAddr(list(map(int, input().rstrip().split(".")))) for _ in range(n)]
