import sys

input=sys.stdin.readline

n=int(input())

a=sorted(list(map(int,input().split())))

min_abs=sys.maxsize
min_comb=None

for i in range(len(a)):
    fixed=i

    left=0
    while fixed==left:
        left+=1

    right=len(a)-1
    while fixed==right:
        right-=1

    while left<right:
        _sum=a[fixed]+a[left]+a[right]
        if abs(_sum)<min_abs:
            min_abs=abs(_sum)
            min_comb=sorted([a[fixed],a[left],a[right]])
        
        if _sum<0:
            left+= 2 if left+1==fixed else 1
        elif _sum>0:
            right-= 2 if right-1==fixed else 1
        else:
            print(*min_comb)
            exit(0)
        
print(*min_comb)