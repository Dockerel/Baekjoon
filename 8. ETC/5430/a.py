import sys
from collections import deque
input=sys.stdin.readline
t=int(input())

def solve():
    cmd=input().rstrip()
    n=int(input())
    arr=input().rstrip()[1:-1].split(",")
    queue=deque(arr)
    flag=0

    if n==0:
        queue=deque([])

    for c in cmd:
        if c=="R":
            flag=1 if flag==0 else 0
        elif c=="D":
            try:
                if flag==0:
                    queue.popleft()
                else:
                    queue.pop()
            except IndexError:
                print("error")
                return
            
    if flag:
        queue.reverse()
    print("["+",".join(queue)+"]")

for i in range(t):
    solve()