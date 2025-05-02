import sys

input = sys.stdin.readline

for _ in range(int(input())):
    grades = sorted([list(map(int, input().split())) for _ in range(int(input()))])
    ret = 1
    min1, min2 = grades[0]
    for i in range(1, len(grades)):
        n1, n2 = grades[i]
        if n1 < min1 or n2 < min2:
            ret += 1
            min1 = min(min1, n1)
            min2 = min(min2, n2)
    print(ret)
