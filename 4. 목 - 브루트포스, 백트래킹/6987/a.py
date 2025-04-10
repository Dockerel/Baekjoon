import sys
from itertools import combinations as comb

input = sys.stdin.readline

ret = []

matches = list(comb(list(range(6)), 2))

types1 = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
types2 = [[0, 0, 1], [0, 1, 0], [1, 0, 0]]

result = None
flag = 0


def go(curr, currStatus):
    global flag
    if curr == len(matches):
        # 검사
        for i in range(18):
            if result[i] != currStatus[i]:
                return
        flag = 1
        return

    team1 = matches[curr][0]
    team2 = matches[curr][1]

    for i in range(3):
        for k in range(3):
            currStatus[3 * team1 + k] += types1[i][k]
            currStatus[3 * team2 + k] += types2[i][k]

        valid = True
        for j in range(18):
            if currStatus[j] > result[j]:
                valid = False
                break
        if valid:
            go(curr + 1, currStatus)

        for k in range(3):
            currStatus[3 * team1 + k] -= types1[i][k]
            currStatus[3 * team2 + k] -= types2[i][k]


for _ in range(4):
    temp = [0] * 18
    result = list(map(int, input().split()))
    flag = 0
    go(0, temp)
    ret.append(flag)

print(*ret)
