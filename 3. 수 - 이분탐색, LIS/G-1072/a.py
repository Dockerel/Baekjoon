import sys
from math import floor

input=sys.stdin.readline

x,y=list(map(int,input().split()))
z=floor(y*100/x)

print(f"z : {z}")

if z>=99:
    print(-1)
    exit(0)

l=0
r=x

ret=-1

while l<=r:
    mid=(l+r)//2
    newZ=floor((y+mid)*100/(x+mid))
    print(f"newZ : {newZ}")
    if z==newZ:
        print("here1")
        l=mid+1
    else:
        print("here2")
        ret=mid
        r=mid-1

print(ret)