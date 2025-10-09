import sys

input = sys.stdin.readline

s = input().strip()

ret = 0

mem = {}


def go(curr, history):

    global ret

    if curr == s:
        if mem.get(history) == None:
            ret += 1
            mem[history] = 1
        return

    # 왼쪽
    for i in range(0, 10):
        temp = str(i) + curr
        if temp in s:
            go(temp, history + f"-{temp}")
    # 오른쪽
    for i in range(0, 10):
        temp = curr + str(i)
        if temp in s:
            go(temp, history + f"-{temp}")


for c in s:
    go(c, c)

print(ret)
