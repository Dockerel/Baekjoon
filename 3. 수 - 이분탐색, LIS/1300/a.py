from collections import deque

n = int(input())
k = int(input())

# 1  2  3  4  5
# 2  4  6  8 10
# 3  6  9 12 15
# 4  8 12 16 20
# 5 10 15 20 25

start = 1
end = n**2

ret = None

while start <= end:
    mid = (start + end) // 2

    cnt = 0
    for i in range(1, n + 1):
        cnt += min(n, mid // i)

    if cnt < k:
        start = mid + 1
    else:
        end = mid - 1
        ret = mid

print(ret)
