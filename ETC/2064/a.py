import sys

input = sys.stdin.readline

n = int(input())


def convertAddr(addr) -> int:
    temp = ""
    for num in addr:
        temp += format(num)
    return int(temp, 2)


addrs = [convertAddr(list(map(int, input().rstrip().split(".")))) for _ in range(n)]
temp_addr = addrs[0]


def isSame() -> bool:
    for i in range(1, len(addrs)):
        if addrs[i - 1] != addrs[i]:
            return False
    return True


cnt = 0

while not isSame():
    for i in range(len(addrs)):
        addrs[i] >>= 1
    cnt += 1

mask = 0xFFFFFFFF
mask >>= cnt
mask <<= cnt


def convertToIp(num) -> str:
    temp = []
    for i in range(4):
        temp.append(str(num % 256))
        num >>= 8
    temp.reverse()
    return ".".join(temp)


print(convertToIp(mask & temp_addr))
print(convertToIp(mask))
