import sys

input=sys.stdin.readline

n=int(input())
a=list(map(int,input().split()))
k=int(input())

st,ed=0,0
curr=a[0]

ret=0

while st<n and ed<n:
    if curr>k:
        ret+=n-ed
        curr-=a[st]
        st+=1
        continue
    ed+=1
    if ed<n:
        curr+=a[ed]

print(ret)