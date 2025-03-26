import sys
from collections import deque

input=sys.stdin.readline

n=int(input())
a=list(map(int,input().split()))
q=deque()

if n==1:
    print(f"{a[0]}\n1")
    exit(0)

q.appendleft([-1,-1])
for i in range(len(a)):
    q.appendleft([a[i],i+1])
q.appendleft([-1,-1])

while len(q)>4:
    curr=q.pop()
    currSize=curr[0]
    if currSize==-1:
        q.appendleft(curr)
        continue

    sumSize=0
    
    prev=q.popleft()
    if prev[0]==-1:
        q.appendleft(prev)
    elif prev[0]<=currSize:
        sumSize+=prev[0]
    else:
        q.appendleft(prev)

    next=q.pop()
    if next[0]==-1:
        q.append(next)
    elif next[0]<=currSize:
        sumSize+=next[0]
    else:
        q.append(next)

    q.appendleft([currSize+sumSize, curr[1]])

if len(q)<4:
    q.appendleft([0,0])
while len(q)>2:
    curr=q.pop()
    if curr[0]!=-1:
        q.appendleft(curr)

print(q[0][0]+q[1][0])
if q[0][0]>q[1][0]:
    print(q[0][1])
else:
    print(q[1][1])