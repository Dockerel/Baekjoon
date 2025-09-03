import sys
from itertools import combinations as comb

input = sys.stdin.readline

ordersNum, woksNum = map(int, input().split())
woks = list(map(int, input().split()))

# 동시에 웍 2개도 가능

possibleWoks = sorted(
    woks + ([] if woksNum == 1 else list(sum(temp) for temp in list(comb(woks, 2))))
)

dp = [float("inf")] * (ordersNum + 1)
dp[0] = 0

for i in range(1, ordersNum + 1):
    for possibleWok in possibleWoks:
        if i - possibleWok < 0:
            break
        dp[i] = min(dp[i], dp[i - possibleWok] + 1)

print(dp[ordersNum] if dp[ordersNum] != float("inf") else -1)
