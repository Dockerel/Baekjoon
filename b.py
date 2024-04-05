from itertools import combinations
n,c = map(int, input().split())
print(len(list(combinations([0]*n,c))))