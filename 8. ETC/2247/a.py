n = int(input())

ret = 0
for i in range(2, n):
    ret += (n // i - 1) * i
    ret %= 1000000
print(ret)
