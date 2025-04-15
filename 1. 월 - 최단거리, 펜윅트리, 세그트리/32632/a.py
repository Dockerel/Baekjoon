import sys
from math import gcd

input = sys.stdin.readline

k, n = list(map(int, input().split()))

# gcd(x,y) = 1 이면 x번 정점과 y번 정점을 잇는 간선이 존재한다.
# gcd(x,y) != 1 이면 x번 정점과 y번 정점을 잇는 간선은 존재하지 않는다.

# 1 이상 N 이하의 정수 K가 주어졌을 때, dist(x,K) = gcd(x,K)를 만족하는 1 이상 N 이하의 정수 x의 개수를 구해보자.

# i → 1 → i 경로가 항상 존재하기에 dist(i, k)는 항상 2 이하라는 점을 이용하면 gcd(i, k)를 구하며 dist(i, k)를 O(1)에 계산할 수 있음

ret = 0

for i in range(1, n + 1):
    if i == k:
        continue
    if i == 1:
        if gcd(i, k) == 1:
            ret += 1
    else:
        if gcd(i, k) <= 2:
            ret += 1

print(ret)
