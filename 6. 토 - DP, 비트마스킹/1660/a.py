n = int(input())

nums = [1]
for i in range(2, 121):
    nums.append(nums[-1] + i)

ret = [1]
for num in nums[1:]:
    temp = ret[-1] + num
    if temp > n:
        break
    ret.append(temp)

dp = [float("inf")] * (n + 1)

dp[0] = 0
dp[1] = 1
for i in range(2, n + 1):
    # 무게 i 만들 수 있는 최소 개수 dp[i]개
    for num in ret:
        if num > i:
            break
        dp[i] = min(dp[i], dp[i - num] + 1)

print(dp[n])
