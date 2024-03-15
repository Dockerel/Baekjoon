import sys


def go(idx, _num):
    global ret
    if idx == len(num) - 1:
        ret = max(ret, _num)
        return

    go(idx + 1, eval(f"{_num}{oper_str[idx]}{num[idx + 1]}"))

    if idx + 2 <= len(num) - 1:
        temp = eval(f"{num[idx + 1]}{oper_str[idx+1]}{num[idx + 2]}")
        go(idx + 2, eval(f"{_num}{oper_str[idx]}{temp}"))


n = int(input())
s = input()

num = []
oper_str = []

for i in range(n):
    if i % 2 == 0:
        num.append(int(s[i]))
    else:
        oper_str.append(s[i])

ret = -sys.maxsize
go(0, num[0])
print(ret)
