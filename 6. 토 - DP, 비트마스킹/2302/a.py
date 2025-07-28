import sys

input = sys.stdin.readline

n = int(input())
m = int(input())
vips = [0] + [int(input()) for _ in range(m)] + [n + 1]

# vip를 기준으로 구간 나누기
# 각 구간별로 경우의 수 구해서 다 곱하기

# 1 -> 1
# 2 -> 2
# 3 -> 3
# 4 -> 5
# 피보나치?

sections = [vips[i] - vips[i - 1] - 1 for i in range(1, m + 2)]

dp = [1, 1]

max_section = max(sections)
if max_section > 1:
    for i in range(2, max_section + 1):
        dp.append(dp[-1] + dp[-2])

ret = 1
for section in sections:
    ret *= dp[section]

print(ret)
