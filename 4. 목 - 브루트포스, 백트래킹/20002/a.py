import sys

input = sys.stdin.readline

n = int(input())
profits = [list(map(int, input().split())) for _ in range(n)]

cuprofits = [[0] * n for _ in range(n)]

for i in range(n):
    for j in range(n):
        temp1 = cuprofits[i][j - 1] if j - 1 >= 0 else 0
        temp2 = cuprofits[i - 1][j] if i - 1 >= 0 else 0
        temp3 = cuprofits[i - 1][j - 1] if i - 1 >= 0 and j - 1 >= 0 else 0
        cuprofits[i][j] = profits[i][j] + temp1 + temp2 - temp3

ret = -float("inf")
for k in range(1, n + 1):
    for i in range(n - k + 1):
        for j in range(n - k + 1):
            # (i,j)에서 k*k 사이즈의 합
            temp1 = cuprofits[i + k - 1][j + k - 1]
            temp2 = cuprofits[i - 1][j + k - 1] if i - 1 >= 0 else 0
            temp3 = cuprofits[i + k - 1][j - 1] if j - 1 >= 0 else 0
            temp4 = cuprofits[i - 1][j - 1] if i - 1 >= 0 and j - 1 >= 0 else 0
            ret = max(ret, temp1 - temp2 - temp3 + temp4)

print(ret)
