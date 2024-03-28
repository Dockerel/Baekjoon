alpha=list(input())
s=list(input())

ret=set()

#add
for i in range(len(s)+1):
    for j in range(len(alpha)):
        temp=s[:i]+[alpha[j]]+s[i:]
        ret.add("".join(temp))

#delete
for i in range(len(s)):
    temp=s.copy()
    del temp[i]
    ret.add("".join(temp))

#replace
for i in range(len(alpha)):
    for j in range(len(s)):
        temp=s.copy()
        if temp[j]!=alpha[i]:
            temp[j]=alpha[i]
            ret.add("".join(temp))

ret=sorted(list(ret))
print(*ret,sep="\n")