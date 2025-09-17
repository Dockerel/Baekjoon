import sys

input = sys.stdin.readline

n = int(input())
nums = [int(input()) for _ in range(n)]

# 0 3 4 5 6 9
# 3 6 0 9 5 4

# 1 4 0 5 3 2

sorted_nums = sorted(nums)
indexes = [sorted_nums.index(num) for num in nums]

deques = []

for index in indexes:
    exists = 0
    for i in range(len(deques)):
        d = deques[i]
        start, end = d[0], d[-1]
        if start - 1 == index or end + 1 == index:
            temp = sorted(d + [index])
            deques[i] = [temp[0], temp[-1]]
            exists = 1
            break
    # 인접한 덱이 있으면 거기 삽입
    if not exists:
        deques.append([index])
    # 없으면 새로 덱 생성

print(len(deques))
