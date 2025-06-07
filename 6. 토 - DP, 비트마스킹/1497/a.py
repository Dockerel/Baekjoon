import sys
from itertools import combinations as comb

input = sys.stdin.readline

codes = []

n, m = list(map(int, input().split()))
for _ in range(n):
    _, code = input().split()
    codes.append(int(code.replace("Y", "1").replace("N", "0"), 2))

songs = 0
guitars = -1

temp = list(range(n))
for i in range(1, n + 1):
    for c in list(comb(temp, i)):
        ret = 0
        for idx in c:
            ret |= codes[idx]
        # 연주 가능한 노래 개수 확인
        temp_songs = 0
        for num in [2**j for j in range(m)]:
            if num & ret:
                temp_songs += 1
        if temp_songs > songs:
            songs = temp_songs
            guitars = i
print(guitars)
