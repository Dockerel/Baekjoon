import sys

input = sys.stdin.readline

for _ in range(int(input())):
    n = int(input())
    s = [c for c in input().strip()][1::]
    nums = []
    ops = []
    toggle = 1
    for c in s:
        if toggle:
            ops.append(c)
        else:
            nums.append(int(c))
        toggle ^= 1
    temp = [0] * n  # temp[i] : i 이후에 0이 아닌 수가 있다
    for i in range(n - 2, -1, -1):
        if temp[i + 1] or nums[i + 1]:
            temp[i] = 1
    found = 0
    for i in range(n):
        if ops[i] == "-" and temp[i]:
            print("NO")
            found = 1
            break
    if not found:
        print("YES")
