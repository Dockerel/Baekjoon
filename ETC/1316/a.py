import sys
from collections import defaultdict
input=sys.stdin.readline
n=int(input())
global ans
ans=0
def groupWord(s):
    global ans
    prev='.'
    d=defaultdict(int)
    for i in range(len(s)):
        if prev=='.' or prev==s[i]:
            prev=s[i]
            d[s[i]]=1
        else:
            if d[s[i]]!=0:
                return
            else:
                prev=s[i]
                d[s[i]]=1
    ans+=1

for i in range(n):
    s=input()
    groupWord(s)

print(ans)