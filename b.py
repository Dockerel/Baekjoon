import sys
input=sys.stdin.readline
n,m=list(map(int,input().rstrip().split()))
ret=[0]*n
for i in range(m):
    b1,b2,k=list(map(int,input().rstrip().split()))
    for j in range(b1-1,b2):
        ret[j]=k
print(*ret)