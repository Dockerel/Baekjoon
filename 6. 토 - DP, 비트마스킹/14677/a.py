import sys

input = sys.stdin.readline

n = int(input())
s = input().strip()

dp = [set() for _ in range(3 * n + 4)]
dp[0].add(s)

success = [0] * (3 * n + 4)
success[0] = 1

curr = 0
while curr < 3 * n and len(dp[curr]):
    target = "BLD"[curr % 3]
    for case in dp[curr]:
        if case[0] == target:
            dp[curr + 1].add(case[1:])
            success[curr + 1] = 1
        if case[-1] == target:
            dp[curr + 1].add(case[:-1])
            success[curr + 1] = 1
    curr += 1

print(curr if success[curr] else curr - 1)
