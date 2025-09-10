import sys,bisect

input=sys.stdin.readline

a=sorted([int(input()) for _ in range(int(input()))])

zeroExists=True
try:
    a.index(0)
except ValueError:
    zeroExists=False

zeroIdx=bisect.bisect_left(a,0)
minus=a[0:zeroIdx][::-1]
plus=a[zeroIdx+1 if zeroExists else zeroIdx:]

ret=0

while len(minus)>1:
    ret+=minus.pop()*minus.pop()

if minus:
    if not zeroExists:
        ret+=minus.pop()

while len(plus)>1:
    n1,n2=plus.pop(),plus.pop()
    ret+=max(n1*n2,n1+n2)
print(ret+sum(plus))