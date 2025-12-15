import sys

input = sys.stdin.readline

pw = input().rstrip()
nth = int(input())

target = "".join([c for c in pw if c in ["1", "2", "6", "7"]])

temp = bin(nth - 1).split("b")[1]
if len(temp) > len(target):
    print(-1)
    exit(0)
temp = "0" * (len(target) - len(temp)) + temp

answer = ""
for i in range(len(target)):
    if temp[i] == "0":
        if target[i] in ["1", "6"]:
            answer += "1"
        else:
            answer += "2"
    else:  # temp[i]=="1"
        if target[i] in ["1", "6"]:
            answer += "6"
        else:
            answer += "7"

curr = 0
for c in pw:
    if c in ["1", "2", "6", "7"]:
        print(answer[curr], end="")
        curr += 1
        continue
    print(c, end="")
