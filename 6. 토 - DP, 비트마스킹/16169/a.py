import sys

input = sys.stdin.readline

n = int(input())

total_time = [0] * (n + 1)
times = [0]
ranks = [[] for _ in range(n + 1)]

for i in range(1, n + 1):
    rank, exec_t = map(int, input().split())
    ranks[rank].append(i)
    times.append(exec_t)

for i in ranks[1]:
    total_time[i] = times[i]

for i in range(1, n):
    for prev in ranks[i]:
        for next in ranks[i + 1]:
            total_time[next] = max(
                total_time[next], (next - prev) ** 2 + total_time[prev] + times[next]
            )

print(max(total_time))
