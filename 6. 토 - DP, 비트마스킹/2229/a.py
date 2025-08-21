import sys

input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))

# 조를 짜는데, 각 조 안에 max-min가 최대가 되도록
# 각 조의 사람 수가 다 달라도 됨
# 사람마다 조를 다 순회하면서 어느 조에 들어갈지 결정
# 조에 들어가거나 새로운 조를 만들거나
# 연속된 학생들을 적당히 나누어

dp = [0] * (n + 1)

for i in range(n):
    _max = _min = a[i]
    for j in range(i, -1, -1):
        _max = max(_max, a[j])
        _min = min(_min, a[j])
        dp[i + 1] = max(dp[i + 1], dp[j] + (_max - _min))

print(dp[n])
