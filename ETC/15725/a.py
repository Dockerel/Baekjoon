s=input()

if 'x' in s:
    temp=s.split('x')[0]
    if temp=='' or temp=='-':
        print(temp+"1")
    else:
        print(temp)
else:
    print(0)