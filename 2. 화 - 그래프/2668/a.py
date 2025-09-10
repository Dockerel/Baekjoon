import sys

input=sys.stdin.readline

n=int(input())

a=[0]+[int(input()) for _ in range(n)]

v=[0 for _ in range(n+4)]

def go(start,idx, nodes):

    global v

    if start==idx:
        for node in nodes:
            v[node]=1
        return
    
    if idx in nodes:
        return
    
    go(start,a[idx],nodes+[idx])
    return

for i in range(1,n+1):
    go(i,a[i],[i])

ret1=0
ret2=[]
for i in range(1,n+1):
    if v[i]==1:
        ret1+=1
        ret2.append(i)

print(ret1)
print(*ret2,sep="\n")