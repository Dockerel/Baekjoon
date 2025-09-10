import sys

input=sys.stdin.readline

n=int(input())
a=list(map(int,input().split()))

ret_abs=sys.maxsize
ret=None

left=0
right=n-1

while left<right:
    _sum=a[left]+a[right]
    if _sum==0:
        ret=[left,right]
        break

    if abs(_sum)<ret_abs:
        ret_abs=abs(_sum)
        ret=[left,right]

    if _sum<0:
        left+=1
    elif _sum>0:
        right-=1

print(f"{a[ret[0]]} {a[ret[1]]}")