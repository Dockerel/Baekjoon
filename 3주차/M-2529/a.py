import sys

input = sys.stdin.readline

n = int(input().rstrip())
signs = list(map(str, input().rstrip().split()))

global _max, _min
_max = "0" * (n + 1)
_min = "9" * (n + 1)


def go(idx, nums, v):
    global _max, _min

    if len(nums) == n + 1:
        _max = str(max(int(_max), int(nums)))
        _min = str(min(int(_min), int(nums)))
        return

    if signs[idx] == ">":
        for i in range(int(nums[idx]) - 1, -1, -1):
            if v[i] == 0:
                temp = v.copy()
                temp[i] = 1
                go(idx + 1, nums + str(i), temp)

    elif signs[idx] == "<":
        for i in range(int(nums[idx]) + 1, 10):
            if v[i] == 0:
                temp = v.copy()
                temp[i] = 1
                go(idx + 1, nums + str(i), temp)


for i in range(10):
    s1, s2 = "", [0] * 10
    s2[i] = 1
    go(0, s1 + str(i), s2)

_max = "0" * (n + 1 - len(_max)) + _max
_min = "0" * (n + 1 - len(_min)) + _min

print(_max)
print(_min)
