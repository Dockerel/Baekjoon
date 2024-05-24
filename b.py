import sys
input=sys.stdin.readline
l1=list(map(int,input().rstrip().split()))
l2=list(map(int,input().rstrip().split()))
print(max(l1[0]+l2[1],l1[1]+l2[0]))