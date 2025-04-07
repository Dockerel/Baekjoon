import sys

input = sys.stdin.readline

n, m = list(map(int, input().split()))

lowJ = highJ = 1
ret = 1e9

jewels = []
for _ in range(m):
    j = int(input())
    jewels.append(j)
    highJ = max(highJ, j)


def canDistribute(jealousy):
    _sum = 0
    for jewel in jewels:
        _sum += jewel // jealousy + (1 if jewel % jealousy else 0)
        if _sum > n:
            return False
    return True


while lowJ <= highJ:
    # 해당 질투심으로 나눠줄 수 있는지
    jealousy = (lowJ + highJ) // 2

    if canDistribute(jealousy):
        # 가능한 경우
        highJ = jealousy - 1
        ret = min(ret, jealousy)
    else:
        # 불가능한 경우
        lowJ = jealousy + 1

print(ret)
