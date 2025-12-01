import sys

input = sys.stdin.readline

n = int(input())
villages = []
total_people = 0

for _ in range(n):
    x, a = map(int, input().split())
    villages.append((x, a))
    total_people += a

# 좌표 기준 정렬
villages.sort()

# 가중 중앙값 찾기
cumsum = 0
for x, a in villages:
    cumsum += a
    if cumsum >= (total_people + 1) // 2:
        print(x)
        exit(0)
