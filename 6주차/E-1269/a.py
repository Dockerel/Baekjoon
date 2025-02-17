import sys

input=sys.stdin.readline

a,b=list(map(int,input().split()))

A=input().split()
B=input().split()

dA={}
dB={}

ret=0

for n in A:
    dA[n]=1
for n in B:
    dB[n]=1
    if dA.get(n)==None:
        ret+=1
for n in A:
    if dB.get(n)==None:
        ret+=1

print(ret)