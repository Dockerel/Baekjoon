# k층 n호
# k-1층 n호까지의 사람 합

# 1층 3호 : 1+2+3
# 0층 3호까지의 사람 합 : 1+2+3

dp=[[0]*20]*20


def go(k,n):
    print(k,n)
    print(dp)
    if dp[k][n]!=0:
        return dp[k][n]
    
    for i in range(1,n+1):
        dp[k][n]+=go(k-1,i)

    return dp[k][n]

t=int(input())
for _ in range(t):
    d = [ [0] * i for i in range(20)]
    for i in range(0,20):
        dp[0][i]=i
    k=int(input())
    n=int(input())
    print(go(k,n))