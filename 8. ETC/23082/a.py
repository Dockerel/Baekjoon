n = int(input())

if n == 0:
    print(0)
    exit(0)

sign = 1 if n > 0 else -1

n = abs(n)

digits = []
while n:
    digits.append(n % 3)
    n //= 3

digits = digits[::-1]

ret = []
carry = 0
for i in range(len(digits) - 1, -1, -1):
    if digits[i] + carry == 3:
        ret.append("0")
        carry = 1
    elif digits[i] + carry == 2:
        ret.append("T")
        carry = 1
    elif digits[i] + carry == 1:
        ret.append("1")
        carry = 0
    else:
        ret.append("0")
        carry = 0
if carry:
    ret.append("1")

temp = "".join(ret[::-1])
if sign == -1:
    temp = temp.replace("T", "t").replace("1", "T").replace("t", "1")
print(temp)
