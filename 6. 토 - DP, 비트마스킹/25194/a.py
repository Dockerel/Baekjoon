import sys

input = sys.stdin.readline

n = int(input())
works = list(map(int, input().split()))

# 월 화 수 목 금 토 일 월 화 수 목 금 토 일 월 화 수 목 금 토 일
#   1  2 3  4 5  6  7 8 9 10 11 12

# 4 11 18

# 4+7*(n-1) 형태

dp = [0] * 7
dp[0] = 1
for w in works:
    temp = dp[:]
    for i in range(7):
        if dp[i]:
            temp[(i + w) % 7] = 1
    dp = temp

print("YES" if dp[4] else "NO")
