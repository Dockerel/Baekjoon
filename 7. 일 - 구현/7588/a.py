import sys

input = sys.stdin.readline

nums = []

while 1:
    n = int(input())
    if n == 0:
        break
    nums.append(n)

max_num = max(nums)
s = [0, 0] + [1] * (max_num + 1)
for i in range(2, int(max_num**0.5) + 1):
    for j in range(i, max_num // i + 1):
        s[i * j] += i
        if i != j:
            s[i * j] += j

for num in nums:
    print(f"\nAmicable numbers between 1 and {num}")
    flag = 1
    for i in range(2, num + 1):
        if s[i] != i and i < s[i] <= max_num and s[s[i]] == i:
            flag = 0
            print(f"{i} {s[i]}")
    if flag:
        print("None")
