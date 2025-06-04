import sys

input = sys.stdin.readline
n, k = list(map(int, input().split()))
a = [int(input()) for _ in range(n)]

min_a = min(a)
start, end = min_a, min_a + k

target_lv = start
while start <= end:
    mid = (start + end) // 2
    lv_sum = 0
    for lv in a:
        lv_sum += mid - lv if mid > lv else 0
    if lv_sum > k:
        end = mid - 1
    else:
        target_lv = mid
        start = mid + 1

print(target_lv)
