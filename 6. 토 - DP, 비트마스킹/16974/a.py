import sys

input = sys.stdin.readline

n, x = map(int, input().split())

# 레벨 - 0 : P
# 레벨 - 1 : BPPPB
# 레벨 - 2 : B BPPPB P BPPPB B

# 1. 전체 레이어의 수
# LV(n)=LV(n-1)*2+3
layers = [1]
patties = [1]
for _ in range(n):
    layers.append(layers[-1] * 2 + 3)
    patties.append(patties[-1] * 2 + 1)

# n 레벨에서 x가 layers[n]//2보다 크면 n-1 레벨에서 x-layers[n]//2-1 에서의 패티수
# 이때 패티 수는 += patty[n-1]+1

ret = 0


def go(n, x):

    global ret

    if n == 0:
        ret += x
        return

    if x > layers[n] // 2:
        ret += patties[n - 1] + 1
        go(n - 1, x - layers[n] // 2 - 1 - (1 if x == layers[n] else 0))
    elif x != 0:
        go(n - 1, x - 1)


go(n, x)

print(ret)
