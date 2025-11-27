import sys,heapq

input = sys.stdin.readline

n = int(input())
intervals = []

for _ in range(n):
    h, o = map(int, input().split())
    start, end = min(h, o), max(h, o)
    intervals.append((end, start))

d = int(input())

# 길이가 d보다 큰 구간 제거
intervals = [(end, start) for end, start in intervals if end - start <= d]

# 끝점 기준 정렬
intervals.sort()

heap = []
max_count = 0

for end, start in intervals:
    # 현재 끝점을 기준으로 철로 범위 [end-d, end] 설정
    heapq.heappush(heap, start)
    
    # 철로 범위를 벗어난 시작점 제거
    while heap and heap[0] < end - d:
        heapq.heappop(heap)
    
    max_count = max(max_count, len(heap))

print(max_count)
