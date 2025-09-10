import sys

input=sys.stdin.readline

key=input().strip()
cipher=input().strip()

tempLen=len(cipher)//len(key)
tempCols=[]
for i in range(0,len(cipher),tempLen):
    tempCols.append(cipher[i:i+tempLen])

# key sort
keyCode=[]
for idx,c in enumerate(key):
    keyCode.append(f"{c}{idx}")
sortedKeyCode=sorted(keyCode)

keyMap={}
for idx,c in enumerate(sortedKeyCode):
    keyMap[c]=idx

result=[[],[],[],[],[],[],[],[],[],[],[],[],[],[]]

for k in keyCode:
    tempCol=tempCols[keyMap[k]]
    for i in range(len(tempCol)):
        result[i].append(tempCol[i])

for r in result:
    if r:
        print("".join(r),end="")