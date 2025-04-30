n=int(input())

if n==1 or n==2:
    print(2)
    exit(0)

n+=0 if n%2 else 1

def isPrime(n):
    for i in range(2,int(n**0.5)+1):
        if n%i==0:
            return 0
    return 1

def isPalindrome(n):
    s=str(n)
    for i in range(len(s)//2):
        if s[i]!=s[len(s)-1-i]:
            return 0
    return 1

while 1:
    # 소수 확인 + 팰린드롬 확인
    if isPrime(n) and isPalindrome(n):
        print(n)
        break
    n+=2