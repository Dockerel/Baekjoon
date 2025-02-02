import math as m

n=int(input())

if n==1:
    print(0)
    exit(0)
if n==4000000:
    print(1)
    exit(0)

primes=[]

def isPrime(num):
    for i in range(2,m.floor((num**0.5)+1)):
        if num%i==0:
            return False
    return True

for i in range(2,n+1):
    if(isPrime(i)):
        primes.append(i)

start=end=ret=0
curr=primes[start]
while 1:
    if primes[end]>n: break
    if curr<n:
        end+=1
        if end==len(primes): break
        curr+=primes[end]
    elif curr>n:
        curr-=primes[start]
        start+=1
    else: # curr==n
        ret+=1
        if start<end:
            curr-=primes[start]
            start+=1
        else:
            break

print(ret)