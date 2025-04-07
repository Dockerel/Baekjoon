import sys, bisect

input=sys.stdin.readline

n=int(input())

a=list(map(int,input().split()))

ret=[]
for num in a:
    if len(ret)==0 or ret[-1]<num:
        ret.append(num)
    else:
        idx=bisect.bisect_left(ret,num)
        if idx<len(ret):
            ret[idx]=num
        else:
            ret.append(num)

print(len(ret))