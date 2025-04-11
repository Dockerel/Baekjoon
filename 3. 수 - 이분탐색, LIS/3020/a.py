import sys
from bisect import bisect_left

input = sys.stdin.readline

n, h = list(map(int, input().split()))
a = [int(input()) for _ in range(n)]
down = sorted(a[::2])
up = sorted(a[1::2])

min_break = sys.maxsize
min_ret = None
for i in range(1, h + 1):
    down_idx = bisect_left(down, i)
    up_idx = bisect_left(up, h + 1 - i)
    should_break = n - (up_idx + down_idx)
    if should_break < min_break:
        min_break = should_break
        min_ret = 1
    elif should_break == min_break:
        min_ret += 1

print(min_break, min_ret)

# ----------------------------------
# |    |    |    |    |    |    |
#      |    |    |    |    |    |  |
#           |  | |  | |  | |  | |  |
#    |    |    |    |    |    | |  |
#    |    |    |    |    |    |    |
# ------------------------------------
