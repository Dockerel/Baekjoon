n=int(input())
m=int(input())
s=input()

ret=0

curr=cnt=0

while curr<m-2:
    if s[curr:curr+3]=='IOI':
        curr+=2
        cnt+=1
        if cnt==n:
            ret+=1
            cnt-=1
    else:
        curr+=1
        cnt=0

print(ret)