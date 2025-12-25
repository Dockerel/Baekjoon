import sys

input = sys.stdin.readline

n, m = map(int, input().split())
planets = [0] + [int(input()) for _ in range(n)]

parents = [i for i in range(n + 1)]


def find_parent(curr):
    while parents[curr] != curr:
        curr = parents[curr]
    return parents[curr]


ret = []
for _ in range(m):
    galaxy1, galaxy2 = map(int, input().split())
    # 1. 각자 조상 찾기
    parent1 = find_parent(galaxy1)
    parent2 = find_parent(galaxy2)

    # 2. 연결
    if parent1 != parent2:
        if parent2 < parent1:
            parent1, parent2 = parent2, parent1
        parents[parent2] = parent1
        planets[parent1] += planets[parent2]
    ret.append(planets[parent1])

print(*ret, sep="\n")
