import sys
input=sys.stdin.readline
l,p=list(map(int,input().rstrip().split()))
_list=list(map(int,input().rstrip().split()))
for i in range(len(_list)):
    _list[i]-=(l*p)
print(*_list)