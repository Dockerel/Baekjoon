import sys
import math
input=sys.stdin.readline
n = int(input().strip())
a = list(map(int, input().strip().split()))
s = [0]
for i in range(n*2):
    s.append(s[-1]+a[i%n])
print(s)
exit(0)
result = 0
for i in range(n-1):
    for i2 in range(1, n+1):
        if s[i2+i]<s[i2-1]:
            result+=math.ceil(abs(s[i2+i]-s[i2-1])/s[n])
print(result)