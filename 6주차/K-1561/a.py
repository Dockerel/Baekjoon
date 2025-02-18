import sys

input=sys.stdin.readline

n,m=list(map(int,input().split()))

times=list(map(int,input().split()))

minT=0
maxT=n*max(times) # 놀이기구 타는 최대 시간

retT=0 # n명 처리 가능한 최소 시간

while minT<=maxT:
    midT=(minT+maxT)//2

    tempNo=0 # 처리 가능한 사람 수
    for t in times:
        tempNo+=((midT//t)+1)
    
    if tempNo<n:
        minT=midT+1
    else:
        maxT=midT-1
        retT=midT

# retT 만큼은 있어야 n명 처리 가능
# retT-1 일때는?

tempNo=0
for t in times:
    tempNo+=((retT-1)//t)+1

for i in range(m):
    if retT%times[i]==0:
        tempNo+=1
    if tempNo==n:
        print(i+1)
        break