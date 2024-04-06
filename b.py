import sys
input=sys.stdin.readline
_list=list(map(int,input().rstrip().split()))
n1,n2=max(_list),min(_list)
for i in range(n2,1,-1):
    if n1%i==0 and n2%i==0:
        print(i)
        break
for i in range(n1,sys.maxsize):
    if i%n1==0 and i%n2==0:
        print(i)
        break