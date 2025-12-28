import sys

input = sys.stdin.readline

n, m = map(int, input().split())

curr_times = list(map(int, input().split()))
for _ in range(n - 1):
    times = list(map(int, input().split()))
    for i in range(m):
        times[i] += min([curr_times[j] for j in range(m) if i != j])
    curr_times = times

print(min(curr_times))
