import sys

input = sys.stdin.readline

nums = []
for _ in range(int(input())):
    nums.append(int(input()))

max_nums = max(nums)

dp = [
    [0] * (max_nums + 1) for _ in range(max_nums + 1)
]  # dp[i][j] : 정수 i를 j 이하의 서로 다른 자연수들의 합으로 나타내는 방법의 수

dp[0] = [1] * max_nums

for i in range(1, max_nums + 1):
    for j in range(1, max_nums + 1):
        dp[i][j] = dp[i][
            j - 1
        ]  # j 사용 안하고 i 만드는 경우 (j-1 이하의 수들로만 i 구성)
        if i >= j:
            dp[i][j] += dp[i - j][
                j - 1
            ]  # i 보다 j가 큰 경우 j를 사용해서 i 만들기 (j-1 이하의 수들로만 i-j 구성)
        dp[i][j] %= 100999

for num in nums:
    print(dp[num][num])
