import sys

input = sys.stdin.readline
n = int(input())
_list = sorted(list(map(int, input().rstrip().split())))

if n < 3:
    print(0)
    exit(0)

ret = 0
for i in range(n):
    tmp = _list[:i] + _list[i + 1 :]
    left, right = 0, len(tmp) - 1
    while left < right:
        _sum = tmp[left] + tmp[right]
        if _sum == _list[i]:
            ret += 1
            break
        if _sum < _list[i]:
            left += 1
        else:
            right -= 1
print(ret)
