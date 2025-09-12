import sys

input = sys.stdin.readline

n = int(input())
brightness = list(map(int, input().split()))
isTurnOn = list(map(int, input().split()))

_sum = sum([brightness[i] for i in range(n) if isTurnOn[i]])

dp = [0] * (n + 1)

for i in range(n):
    if isTurnOn[i]:
        dp[i] = -brightness[i]
        dp[i] = max(
            dp[i], dp[i - 1] - brightness[i]
        )  # 새로운 구간을 시작할건지, 이전에 트렌드(뒤집기)에 편승할건지
    else:
        dp[i] = brightness[i]
        dp[i] = max(
            dp[i], dp[i - 1] + brightness[i]
        )  # 새로운 구간을 시작할건지, 이전에 트렌드(뒤집기)에 편승할건지

print(max(dp[:-1]) + _sum)
