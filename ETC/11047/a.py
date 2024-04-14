import sys
input=sys.stdin.readline
n,k=list(map(int,input().rstrip().split()))
vals=[]
for _ in range(n):
    vals.append(int(input()))
vals=vals[::-1]
ret=0
for v in vals:
    if v<=k:
        temp=k//v
        k-=(temp*v)
        ret+=temp
print(ret)