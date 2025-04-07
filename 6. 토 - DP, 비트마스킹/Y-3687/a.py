t = int(input())

dp = [1e54, 1e54, 1, 7, 4, 2, 6, 8] + [1e54] * 100

min_d = [0, 0, 1, 7, 4, 2, 0, 8]

for i in range(8, 100 + 1):
    for j in range(2, len(min_d)):
        dp[i] = min(dp[i], dp[i - j] * 10 + min_d[j])

for _ in range(t):
    n = int(input())

    max_num = ""
    if n % 2:
        max_num = "7" + "1" * ((n - 3) // 2)
    else:
        max_num = "1" * (n // 2)

    print(f"{dp[n]} {max_num}")
