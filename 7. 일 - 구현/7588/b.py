a=[]
r=range
p=print
while 1:
    n=int(input())
    if n==0:break
    a.append(n)
m=max(a)
s=[0,0]+[1]*(m+1)
for i in r(2,int(m**0.5)+1):
    for j in r(i,m//i+1):
        s[i*j]+=i
        if i!=j:s[i*j]+=j
for q in a:
    p(f"\nAmicable numbers between 1 and {q}")
    if q<284:p("None");continue
    for i in r(2,q+1):
        if s[i]!=i and i<s[i]<=m and s[s[i]]==i:
            f=0
            p(f"{i} {s[i]}")
