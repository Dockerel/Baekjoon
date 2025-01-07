import sys
from collections import deque

input=sys.stdin.readline

cards=deque()

n,k=list(map(int,input().split()))

for i in range(1,n+1):
    nums=list(map(int,input().split()))
    for num in nums:
        cards.append([i,num])

while len(cards)>1:
    temp1=cards.popleft()
    num=temp1[1]
    for _ in range(num-1):
        temp2=cards.popleft()
        cards.append(temp2)

print(*cards[0])