import sys

input=sys.stdin.readline

s,c=list(map(int,input().split()))

ls=[]
for _ in range(s):
    l=int(input())
    ls.append(l)

minL=1
maxL=max(ls)

ret=0

while minL<=maxL:
    midL=(minL+maxL)//2

    cnt=0
    for l in ls:
        cnt+=(l//midL)
         
    if cnt<c:
        maxL=midL-1
    else:
        ret=midL
        minL=midL+1

print(sum(ls)-c*ret)