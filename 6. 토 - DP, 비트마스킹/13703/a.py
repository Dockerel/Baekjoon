k, n = map(int, input().split())

if k == 0:
    print(0)
    exit(0)

dp = {-k: 1}

for _ in range(n):
    new_dp = {}
    for tempK, v in dp.items():
        new_dp[tempK - 1] = new_dp.get(tempK - 1, 0) + v
        if tempK + 1 < 0:
            new_dp[tempK + 1] = new_dp.get(tempK + 1, 0) + v
    dp = new_dp

print(sum([v for k, v in dp.items() if k < 0]))
