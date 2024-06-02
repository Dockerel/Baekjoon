import sys

input = sys.stdin.readline

target = int(input())
gojang = int(input())
gojang_btn = list(map(int, input().rstrip().split()))

btns = [1] * 10
for num in gojang_btn:
    btns[num] = 0

ret = sys.maxsize


def btn_check(num):
    for c in str(num):
        if btns[int(c)] == 0:
            return False
    return True


ret = min(ret, abs(target - 100))
for i in range(0, 1000001):
    if btn_check(i):
        ret = min(ret, len(str(i)) + abs(target - i))

print(ret)
