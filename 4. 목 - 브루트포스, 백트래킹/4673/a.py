def isSelfNb(n):
    for i in range(1,n+1):
        ret=i
        s=str(i)
        for j in range(len(s)):
            ret+=int(s[j])
        if ret==n:
            return
    print(n)

for i in range(1,10001):
    isSelfNb(i)