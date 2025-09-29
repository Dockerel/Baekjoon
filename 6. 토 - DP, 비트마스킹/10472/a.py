import sys
from collections import deque

input = sys.stdin.readline

t = int(input())

changes = [416, 464, 200, 308, 186, 89, 38, 23, 11]


def go(target):
    if target == 0:
        print(0)
        return
    visited = [1] + [0] * 512
    q = deque()
    q.append((0, 0))
    while q:
        currBoard, curr = q.popleft()
        for change in changes:
            temp = currBoard ^ change
            if temp == target:
                print(curr + 1)
                return
            if visited[temp] == 0:
                visited[temp] = 1
                q.append((temp, curr + 1))


for _ in range(t):
    go(
        int(
            "".join([input().strip() for i in range(3)])
            .replace("*", "1")
            .replace(".", "0"),
            2,
        )
    )
