import sys
input=sys.stdin.readline

def go(a,b):
    if b%a==0:
        print("factor")
    elif a%b==0:
        print("multiple")
    else:
        print("neither")

while 1:
    n1,n2=list(map(int,input().rstrip().split()))
    if not n1 and not n2:
        break
    go(n1,n2)