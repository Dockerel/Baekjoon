import sys

input = sys.stdin.readline

win, lose, draw = map(float, input().split())

dp = {2000: 1}

for _ in range(20):
    new_dp = {}
    for k, v in dp.items():
        new_dp[k + 50] = new_dp.get(k + 50, 0) + v * win
        new_dp[k - 50] = new_dp.get(k - 50, 0) + v * lose
        new_dp[k] = new_dp.get(k, 0) + v * draw
    dp = new_dp

ret = [0] * 5
for k, v in dp.items():
    if 1000 <= k <= 1499:
        ret[0] += v
    elif 1500 <= k <= 1999:
        ret[1] += v
    elif 2000 <= k <= 2499:
        ret[2] += v
    elif 2500 <= k <= 2999:
        ret[3] += v
    elif 3000 <= k <= 3499:
        ret[4] += v

for p in ret:
    print("{:.8f}".format(p))
