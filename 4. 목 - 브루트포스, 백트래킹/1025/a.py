import sys

n, m = map(int, input().split())

ret = -1

nums = [[c for c in input().strip()] for _ in range(n)]

for i in range(n):
    for j in range(m):
        for y in range(-n + 1, n):
            for x in range(-m + 1, m):
                currY, currX = i, j
                temp = []
                while 0 <= currY < n and 0 <= currX < m:
                    temp.append(nums[currY][currX])
                    currY += y
                    currX += x
                    if y == x == 0:
                        break
                if len(temp) == 0:
                    continue
                for idx in range(1, len(temp) + 1):
                    num = int("".join(temp[:idx]))
                    if int(num**0.5) ** 2 == num:
                        ret = max(ret, num)

print(ret)
