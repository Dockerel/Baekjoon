# 왼쪽이나 오른쪽에서부터 차례대로 M개 이하로 지워서 양쪽 끝 값의 차이의 최대값 만들기

import sys

input = sys.stdin.readline

n, m = map(int, input().split())
a = list(map(int, input().split()))

front = [a[0]]
for i in range(1, n):
    front.append(min(front[-1], a[i]))
back = [a[-1]]
for i in range(n - 2, -1, -1):
    back.append(max(back[-1], a[i]))
back.reverse()

ret = -float("inf")

for i in range(m + 1):
    ret = max(ret, back[n - 1 - m + i] - front[i])

print(ret)
