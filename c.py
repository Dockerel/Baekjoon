import random


# 로또 확률
idx=0
while 1:
    idx+=1
    n=random.random()
    if n<=(1/8145060):
        print(f"당첨 : {n} / {idx}")
        break