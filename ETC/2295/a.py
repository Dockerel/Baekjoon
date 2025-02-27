import sys, bisect

input=sys.stdin.readline

n=int(input())

nums=[int(input()) for _ in range(n)]
nums=sorted(nums)

sums=set()

for i in range(len(nums)):
    for j in range(len(nums)):
        sums.add(nums[i]+nums[j])

sums=sorted(sums)

for i in range(len(nums)-1,0,-1):
    for j in range(i-1,-1,-1):
        idx=bisect.bisect_left(sums,nums[i]-nums[j])
        if sums[idx]==nums[i]-nums[j]:
            print(nums[i])
            exit(0)