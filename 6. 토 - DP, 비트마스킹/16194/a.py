import sys

input = sys.stdin.readline

n = int(input())
p = [0] + list(map(int, input().split()))

dp = [0] + [sys.maxsize] * (n + 1)

for i in range(1, n + 1):  # 개수
    price = p[i]  # 가격
    for j in range(1, n + 1):  # 총 가격
        if j - i >= 0:
            dp[j] = min(dp[j], dp[j - i] + price)

print(dp[n])
