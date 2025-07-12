import sys

sys.setrecursionlimit(4000)
input = sys.stdin.readline

nums = []
for _ in range(int(input())):
    nums.append(int(input()))

max_nums = max(nums)

dp = [[-1] * (max_nums + 1) for _ in range(max_nums + 1)]


def go(pos, count):
    global dp
    if pos >= count:
        return 1 if pos == count else 0
    if count <= 0:
        return 1 if count == 0 else 0
    if dp[pos][count] != -1:
        return dp[pos][count]
    dp[pos][count] = (go(pos + 1, count) + go(pos + 1, count - pos)) % 100999
    return dp[pos][count]


go(1, max_nums)

for num in nums:
    print(go(1, num))
