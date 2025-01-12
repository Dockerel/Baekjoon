n = int(input())
l1 = list(map(int, input().split()))
t, p = map(int, input().split())

ret = 0

for num in l1:
    ret += (num // t) + (0 if num % t == 0 else 1)

print(f"{ret}\n{n//p} {n%p}\n")
