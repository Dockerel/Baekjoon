import sys
from collections import deque

input = sys.stdin.readline

n = int(input())

graph = {}
for i in range(1, n + 1):
    friends = list(map(int, input().split()))
    graph[i] = []
    for f in friends:
        if f == 0:
            break
        graph[i].append(f)

m = int(input())
rumor_yupojas = list(map(int, input().split()))

# 루머 믿는지 여부 관리 테이블
rumor_trust = [-1] * (n + 1)
q = deque()
for ry in rumor_yupojas:
    rumor_trust[ry] = 0
    q.append((0, ry))

trust_count = [0] * (n + 1)


while q:
    curr_time, curr = q.popleft()

    for neighbor in graph[curr]:
        if rumor_trust[neighbor] != -1:
            continue

        # 인접 노드의 카운터 증가
        trust_count[neighbor] += 1

        total = len(graph[neighbor])
        required = (total + 1) // 2

        if trust_count[neighbor] >= required:
            rumor_trust[neighbor] = curr_time + 1
            q.append((curr_time + 1, neighbor))

print(*rumor_trust[1:])
