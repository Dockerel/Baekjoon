import sys

sys.setrecursionlimit(10000)

input = sys.stdin.readline

n = int(input())
s = input().strip()

# 주기 찾는 문제 -> 2000^2 브루트포스 가능

kituramiTemp = None


def dfs(curr, freq):

    global kituramiTemp

    if curr >= n or s[curr] != "#":
        return

    kituramiTemp[curr] = "#"
    dfs(curr + freq, freq)


kituramiRet = float("inf")
for freq in range(
    1, n
):  # 최대 주기 케이스 : #...# - n개의 문자열에 대해 n-1 주기 1마리
    # dfs
    kituramiTemp = ["."] * n
    kituramiCnt = 0
    for curr in range(0, n):
        if s[curr] == "#" and kituramiTemp[curr] != "#":
            kituramiCnt += 1
            dfs(curr, freq)  # curr, 주기

    flag = 1
    for i in range(0, n):
        if s[i] != kituramiTemp[i]:
            flag = 0
            break
    if flag:
        kituramiRet = min(kituramiRet, kituramiCnt)

print(kituramiRet)
