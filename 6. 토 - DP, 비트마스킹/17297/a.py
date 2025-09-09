m = int(input())

dp = [0, 5, 13]

while dp[-1] < m:
    dp.append(dp[-1] + dp[-2] + 1)


def go(curr, n):  # messi(n)에서 curr 찾기
    # messi(n-1) + ' ' + messi(n-2)

    if n == 2:
        return "Messi Gimossi"[curr - 1]

    # 1. 공백인 경우
    if curr == dp[n - 1] + 1:
        return " "
    # 2. messi(n-1)에 포함되는 경우
    if curr <= dp[n - 1]:
        return go(curr, n - 1)
    # 3. messi(n-2)에 포함되는 경우
    return go(curr - dp[n - 1] - 1, n - 1)


ret = go(m, len(dp) - 1)
print(ret if ret != " " else "Messi Messi Gimossi")
