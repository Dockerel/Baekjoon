import sys

input = sys.stdin.readline

n = int(input())
amounts = list(map(int, input().split()))

csum = [0] * n
csum[0] = amounts[0]
for i in range(1, n):
    csum[i] = csum[i - 1] + amounts[i]

# 벌이 양 끝, 꿀통이 중간
answer = csum[n - 2] - csum[0] + max(amounts[1:-1])

# 벌 - 벌 - 꿀통
for i in range(1, n - 1):
    a = csum[n - 1] - csum[0] - amounts[i]
    b = csum[n - 1] - csum[i]
    answer = max(answer, a + b)

# 꿀통 - 벌 - 벌
for i in range(1, n - 1):
    a = csum[n - 2] - amounts[i]
    b = csum[i - 1]
    answer = max(answer, a + b)

print(answer)
