import sys
from collections import defaultdict

sys.setrecursionlimit(1000000)

input = sys.stdin.readline

n, r, q = map(int, input().split())

graph = defaultdict(list)

for _ in range(n - 1):
    n1, n2 = map(int, input().split())
    graph[n1].append(n2)
    graph[n2].append(n1)

# logic
dp = [0] * (n + 1)  # dp[i] : 정점 i를 루트로 하는 서브트리에 속한 정점의 수
v = [0] * (n + 1)


def go(curr):
    global dp, v

    v[curr] = 1

    ret = 1
    for nd in graph[curr]:
        if v[nd] == 0:
            ret += go(nd)
    dp[curr] = ret
    return ret


go(r)

for _ in range(q):
    print(dp[int(input())])
