import sys

input=sys.stdin.readline

n=int(input())
a=list(map(int,input().split()))
x=int(input())

temp=[]
for num in a:
    if num<x:
        temp.append(num)
a=sorted(temp)
n=len(a)

st=ret=0
ed=n-1

while st<ed:
    _sum=a[st]+a[ed]
    if _sum==x:
        ret+=1
        st+=1
    elif _sum<x:
        st+=1
    else:
        ed-=1


print(ret)