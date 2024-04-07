n=int(input())
for i in range(n,0,-1):
    temp=0
    temp+=i
    s=str(i)
    for j in range(len(s)):
        temp+=int(s[j])
    if temp==n:
        print(i)
        exit(0)
print(n)