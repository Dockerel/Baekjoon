import sys, bisect

input=sys.stdin.readline

n=int(input())

a=list(map(int,input().split()))

dp=[0]*(n+4)

ret=[]
for i in range(n):
    if len(ret)==0 or ret[-1]<a[i]:
        ret.append(a[i])
        dp[i]=len(ret)
    else:
        idx=bisect.bisect_left(ret,a[i])
        if idx<len(ret):
            ret[idx]=a[i]
            dp[i]=idx+1
        else:
            ret.append(a[i])
            dp[i]=len(ret)

currVal=currIdx=-1
for i in range(n):
    if currVal<dp[i]:
        currVal=dp[i]
        currIdx=i


st=[a[currIdx]]
for i in range(currIdx-1,-1,-1):
    if a[i]<a[currIdx] and dp[i]==dp[currIdx]-1:
        st.append(a[i])
        currIdx=i
        dp[currIdx]=dp[i]

print(len(ret))
print(*st[::-1])