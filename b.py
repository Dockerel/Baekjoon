import sys
input=sys.stdin.readline
n,m=list(map(int,input().rstrip().split()))
for _ in range(n):
    s=list(input().rstrip())
    s.reverse()
    print("".join(s))