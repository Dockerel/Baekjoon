import sys

input = sys.stdin.readline
n, q = list(map(int, input().split()))
_list = list(map(int, input().split()))
rotate = 0

for _ in range(q):
    query = list(map(int, input().split()))
    if query[0] == 1:
        _list[(rotate + query[1] - 1) % n] += query[2]
    elif query[0] == 2:
        rotate -= query[1]
    elif query[0] == 3:
        rotate += query[1]

for i in range(rotate, rotate + n):
    print(_list[i % n], end=" ")

# 1 2 3 4 5 : ( 0 + 1 -1)%5=0(1):rotate 배열에서 = (1): 원래 배열에서
# 2 3 4 5 1 : (+1 + 1 -1)%5=1(2):rotate 배열에서 = (2): 원래 배열에서
# 5 1 2 3 4 : (-1 + 1 -1)%5=4(5):rotate 배열에서 = (5): 원래 배열에서
