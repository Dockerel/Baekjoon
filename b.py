import sys

input = sys.stdin.readline

ret=[]

n1,n2 = list(map(int,input().rstrip().split()))
l1=list(map(int,input().rstrip().split()))
l2=list(map(int,input().rstrip().split()))

i,j=0,0

while i<n1 and j<n2:
    if l1[i]<l2[j]:
        ret.append(l1[i])
        i+=1
    else:
        ret.append(l2[j])
        j+=1
if i<n1:
    ret+=l1[i:n1]
if j<n2:
    ret+=l2[j:n2]

print(*ret,sep=" ")