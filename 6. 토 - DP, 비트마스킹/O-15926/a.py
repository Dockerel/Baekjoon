import sys

input=sys.stdin.readline

n=int(input())
s=input().strip()

ret=["0"]*n

st=[]

for i in range(n):
    if s[i]=='(':
        st.append([i,'('])
        continue
    
    if len(st) and st[len(st)-1][1]=='(':
        idx, _ = st.pop()
        ret[idx]=ret[i]="1"

max_ret=len(max("".join(ret).split("0"),key=len))

print(max_ret if max_ret is not None else "0")