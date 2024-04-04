global ret
ret=0

_list=[]

def hanoi(n, source, target, auxiliary):
    global ret
    ret+=1
    if n == 1:
        _list.append([source,target])
        return
    hanoi(n-1, source, auxiliary, target)
    _list.append([source,target])
    hanoi(n-1, auxiliary, target, source)

# 하노이 탑 문제를 해결하는 함수 호출
n = int(input())
hanoi(n, '1', '3', '2')  # A: 출발지, B: 보조지, C: 목적지
print(ret)
for it in _list:
    print(*it)