import sys, heapq

input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    files = list(map(int, input().split()))
    heapq.heapify(files)
    ret = 0
    while len(files) >= 2:
        temp = heapq.heappop(files) + heapq.heappop(files)
        ret += temp
        heapq.heappush(files, temp)
    print(ret)
