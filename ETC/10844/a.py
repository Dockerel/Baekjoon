n=int(input())

prv=9

for i in range(1,n):
    prv=(prv*2-i)%1000000000

print(prv)

# 1 -> 10,12
# 2 -> 21,23
# 3 -> 32,34
# 4 -> 43,45
# 5 -> 54,56
# 6 -> 65,67
# 7 -> 76,78
# 8 -> 87,89
# 9 -> 98

# 10
# 21
# 32,12
# 43,23
# 54,34
# 65,45
# 76,56
# 87,67
# 98,78
# 89