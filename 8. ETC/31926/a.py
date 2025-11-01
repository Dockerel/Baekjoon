from math import log2

# N=1 : daldidalgo daldidan : 10
# N=2 : d a l d i dal g o daldidalgo daldida n : 11
# N=3 : d a l d i dal g o daldidalgo daldidalgodaldida n : 11
# N=4 : d a l d i dal g o daldidalgo daldidalgodaldidalgo daldida n : 12
# N=5 : d a l d i dal g o daldidalgo daldidalgodaldidalgo daldidalgodaldida n : 12
# N=6 : d a l d i dal g o daldidalgo daldidalgodaldidalgo daldidalgodaldidalgodaldida n : 12
n = int(input())
print(10 + int(log2(n)))
