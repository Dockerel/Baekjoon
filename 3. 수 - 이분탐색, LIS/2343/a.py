import sys

input=sys.stdin.readline

n,m=list(map(int,input().split()))

times=list(map(int,input().split()))

lw=max(times)
high=sum(times)

ret=sys.maxsize

while lw<=high:
    mid=(lw+high)//2 # 블루레이 하나당 크기
    
    # mid 크기로 m개 이하의 블루레이로 만드는게 가능한지 확인
    curr=cnt=0
    for t in times:
        if curr+t>mid:
            cnt+=1
            curr=t
        else:
            curr+=t
    if curr>0:
        cnt+=1
    
    if cnt<=m:
        ret=min(ret,mid)
        high=mid-1
    else:
        lw=mid+1

print(ret)