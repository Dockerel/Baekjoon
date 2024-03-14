import datetime as dt

ad=list(map(int,input().split()))
start=dt.date(ad[0],ad[1],ad[2])
tmp=dt.date(ad[0]+1000,ad[1],ad[2])
bd=list(map(int,input().split()))
finish=dt.date(bd[0],bd[1],bd[2])
ret1=(finish-start).days
ret2=(tmp-start).days
if(ret2>ret1): print(f"D-{ret1}")
else: print("gg")
