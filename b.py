import sys
input=sys.stdin.readline
d=dict()
s=input()
for i in range(len(s)):
    if d.get(s[i])==None:
        d[s[i]]=i

for i in range(ord('a'),ord('z')+1):
    if d.get(chr(i))==None:
        print(-1,end=" ")
    else:
        print(d[chr(i)],end=" ")
print()