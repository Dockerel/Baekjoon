import sys

input = sys.stdin.readline

n = int(input())
_list = list(map(int, input().split()))

largest = [_list[0]]
_max = _list[0]

for i in range(1, len(_list)):
    temp = _list[i] + max(0, largest[-1])
    _max = max(_max, temp)
    largest.append(temp)

print(_max)
