import sys

input = sys.stdin.readline

n = int(input())
a = sorted(list(map(int, input().split())))

# 토끼, 고양이 줄에 1열로 세울 수 있는지
# 서로 중복되는 개수만큼 *2
# 마지막에 *2

rabbits = []
cats = []

flag = 1

ret = 1
try:
    for num in a:
        if num == 0:
            if len(rabbits) == 0:
                rabbits.append(num)
            elif len(cats) == 0:
                cats.append(num)
            else:
                flag = 0
                break
            continue
        if rabbits[-1] == num - 1:
            rabbits.append(num)
        elif cats[-1] == num - 1:
            cats.append(num)
        else:
            flag = 0
            break
except:
    flag = 0

if not flag:
    print(0)
    exit(0)

if len(rabbits) == len(cats):
    print(2 ** len(rabbits))
else:
    print(2 ** (min(len(rabbits), len(cats)) + 1))
