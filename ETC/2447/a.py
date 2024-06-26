n=int(input())
a=[[" "]*n for _ in range(n)]

def oneSet(y,x):
  for i in range(3):
    for j in range(3):
      if i==1 and j==1:
        continue
      a[y+i][x+j]="*"

def go(y,x,num):
  if num==1:
    oneSet(y,x)
    return
  
  for i in range(3):
    for j in range(3):
      if i==1 and j==1:
        continue
      go(y+i*num,x+j*num,num//3)

go(0,0,n//3)

for i in range(n):
  for j in range(n):
    print(a[i][j],end="")
  print()
