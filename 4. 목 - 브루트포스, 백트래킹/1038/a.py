n=int(input())

ret=-1

def recur(strNum, curr):
    
    global ret

    if curr==0:
        ret+=1
    if ret==n:
        print(strNum)
        exit(0)
    
    lastNum=int(strNum[-1])
    for i in range(0,lastNum):
        recur(strNum+f"{i}",curr-1)

def go(curr):
    for i in range(0,9+1):
        recur(f"{i}",curr-1)

for i in range(1,10+1):
    go(i)

print(-1)