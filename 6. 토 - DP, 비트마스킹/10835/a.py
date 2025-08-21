import sys

input = sys.stdin.readline

sys.setrecursionlimit(10**6)

# 왼, 오 같은 개수의 카드
# 왼 or 둘다 버리면 점수 없음
# 왼>오 인 경우 오른쪽 버리면서 오른쪽만큼 점수 획득
# 최종 점수의 최댓값?

n = int(input())
left = list(map(int, input().split()))
right = list(map(int, input().split()))

# 왼쪽 버린 개수, 오른쪽 버린 개수

dp = [[-1] * (n + 1) for _ in range(n + 1)]


def go(lCurr, rCurr):

    global dp

    if dp[lCurr][rCurr] != -1:
        return dp[lCurr][rCurr]

    if lCurr == n or rCurr == n:
        return 0

    if left[lCurr] > right[rCurr]:
        dp[lCurr][rCurr] = max(dp[lCurr][rCurr], go(lCurr, rCurr + 1) + right[rCurr])
    else:
        dp[lCurr][rCurr] = max(dp[lCurr][rCurr], go(lCurr + 1, rCurr))
        dp[lCurr][rCurr] = max(dp[lCurr][rCurr], go(lCurr + 1, rCurr + 1))

    return dp[lCurr][rCurr]


print(go(0, 0))
