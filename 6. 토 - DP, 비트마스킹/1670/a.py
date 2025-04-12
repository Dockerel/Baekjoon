n=int(input())//2

dp=[0]*5004

dp[0]=1

for i in range(1,n+1):
    temp=0
    for j in range(i):
        temp+=dp[j]*dp[i-1-j]
    dp[i]=temp
    dp[i]%=987654321

print(dp[n])