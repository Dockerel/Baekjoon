n=int(input())

if n==0:
    print("*")
    exit(0)

star=[[" "]*(5**n) for _ in range(5**n)]

length=5**(n-1)

def go(y,x,curr):

    global star

    if curr==0:
        star[y][x]="*"
        return
    
    length=5**(curr-1)
    
    go(y+0,x+length*2,curr-1)

    go(y+length*1,x+length*2,curr-1)

    go(y+length*2,x+length*0,curr-1)
    go(y+length*2,x+length*1,curr-1)
    go(y+length*2,x+length*2,curr-1)
    go(y+length*2,x+length*3,curr-1)
    go(y+length*2,x+length*4,curr-1)

    go(y+length*3,x+length*1,curr-1)
    go(y+length*3,x+length*2,curr-1)
    go(y+length*3,x+length*3,curr-1)

    go(y+length*4,x+length*1,curr-1)
    go(y+length*4,x+length*3,curr-1)

go(0,length*2,n-1)

go(length*1,length*2,n-1)

go(length*2,length*0,n-1)
go(length*2,length*1,n-1)
go(length*2,length*2,n-1)
go(length*2,length*3,n-1)
go(length*2,length*4,n-1)

go(length*3,length*1,n-1)
go(length*3,length*2,n-1)
go(length*3,length*3,n-1)

go(length*4,length*1,n-1)
go(length*4,length*3,n-1)

for line in star:
    print(*line,sep="")