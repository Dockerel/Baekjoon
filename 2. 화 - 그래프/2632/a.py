import sys

input=sys.stdin.readline

n=int(input())

a,b=list(map(int,input().split()))

nums=sorted([int(input()) for _ in range(a+b)])

while n<nums[-1]:
    nums.pop()
nums=nums[::-1]

ret=0

def go(idx, curr):
    global ret
    if curr==n:
        ret+=1
        return
    if idx==a+b:
        return
    if curr>n:
        return

    go(idx+1,curr+nums[idx])
    go(idx+1,nums[idx])

go(0,0)

print(ret)