import sys, heapq

input = sys.stdin.readline

n, m = map(int, input().split())
corns = [list(map(int, input().split())) for _ in range(n)]
k = int(input())

visited = [[0] * m for _ in range(n)]

pq = []
for i in range(n):
    for j in range(m):
        if (i == 0 or i == n - 1) or (j == 0 or j == m - 1):
            heapq.heappush(pq, (-corns[i][j], i, j))
            visited[i][j] = 1

dy = [1, -1, 0, 0]
dx = [0, 0, 1, -1]

for _ in range(k):
    y, x = heapq.heappop(pq)[1:]
    print(f"{y+1} {x+1}")
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if ny < 0 or ny >= n or nx < 0 or nx >= m or visited[ny][nx] == 1:
            continue
        heapq.heappush(pq, (-corns[ny][nx], ny, nx))
        visited[ny][nx] = 1
