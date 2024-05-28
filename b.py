import sys
input=sys.stdin.readline
n=int(input())
_list1=list(map(int,input().rstrip().split()))
_set=set()
for num in _list1:
    _set.add(num)
_list2=sorted(_set)
_dict=dict()
idx=0
for num in _list2:
    _dict[num]=idx
    idx+=1
for num in _list1:
    print(_dict[num],end=" ")
