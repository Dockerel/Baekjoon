import sys

input = sys.stdin.readline

n = int(input())
a = list(map(int, input().split()))

# 4 3 6 7 8 9 10 2 1 5

# 4 6 7 8 9 10
# 3 5
# 2
# 1

stacks = {0: None, 1: None, 2: None, 3: None}

flag1 = True
for num in a:

    # stack push
    loc = None
    size = float("inf")
    for k in stacks.keys():
        value = stacks[k]
        if value is None or value > num:
            continue
        if num - value < size:
            loc = k
            size = num - value

    if loc == None:
        # 빈 스택 있는지 확인
        flag2 = False
        for k in stacks.keys():
            if stacks[k] is None:
                stacks[k] = num
                flag2 = True
                break
        if not flag2:
            flag1 = False
    else:
        stacks[loc] = num

    if not flag1:
        print("NO")
        exit(0)

print("YES")
