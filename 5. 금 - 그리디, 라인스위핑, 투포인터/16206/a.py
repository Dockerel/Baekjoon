import sys
import heapq

input = sys.stdin.readline

n, m = map(int, input().split())
rolls = list(map(int, input().split()))

ret = 0

# 1. 10 배수 롤부터 자르기
baesu_10 = []
no_baesu_10 = []
for roll in rolls:
    if roll == 10:
        ret += 1
        continue
    if roll % 10 == 0:
        baesu_10.append(roll)
    else:
        no_baesu_10.append(roll)

heapq.heapify(baesu_10)
while baesu_10:
    temp = heapq.heappop(baesu_10)
    if m == 0:
        break
    avail_cut = min(m, temp // 10 - 1)
    m -= avail_cut
    if avail_cut == temp // 10 - 1:
        ret += avail_cut + 1
    else:
        ret += avail_cut

# 2. 10 배수 아닌 롤 자르기
ret += min(sum([num // 10 for num in no_baesu_10]), m)

print(ret)
