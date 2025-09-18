import sys

input = sys.stdin.readline

n = int(input())

strings = [input().strip() for _ in range(2 * n - 2)]

sortedStrings = sorted(strings, key=len)

prefix, suffix = sortedStrings[-2], sortedStrings[-1]
fullString1 = sortedStrings[-1] + sortedStrings[-2][-1]
fullString2 = sortedStrings[-2] + sortedStrings[-1][-1]

# 체크 해야 하는 것
# 1. 모든 string이 접두사/접미사인지
# 2. 문자열 길이별 P와 S의 개수가 같은지

for fullString in [fullString1, fullString2]:
    valid = 1
    result = [None] * (2 * n - 2)
    balance = [0] * (n + 1)
    for i in range(len(strings)):
        string = strings[i]
        if not fullString.startswith(string) and not fullString.endswith(string):
            valid = 0
            break
        if fullString.startswith(string) and fullString.endswith(string):
            continue
        if fullString.startswith(string):
            result[i] = "P"
            balance[len(string)] -= 1
        else:
            result[i] = "S"
            balance[len(string)] += 1

    if not valid:
        continue

    for i in range(2 * n - 2):
        if result[i] != None:
            continue
        string = strings[i]
        if balance[len(string)] < 0:
            balance[len(string)] += 1
            result[i] = "S"
        else:
            balance[len(string)] -= 1
            result[i] = "P"

    print(f'{fullString}\n{"".join(result)}')
    break
