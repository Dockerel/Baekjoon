n=int(input())

if n%2:
    print(0)
    exit(0)

# dp[k]=dp[k-2]+2*(dp[k-2]+dp[k-4]+...+dp[0])

dp=[1,0,3,0]+[0]*30

def go(curr):
    if dp[curr]!=0:
        return dp[curr]
    temp=0
    for i in range(2,curr+1,2):
        temp+=go(curr-i)
    dp[curr]=go(curr-2)+2*temp
    return dp[curr]

print(go(n))