n = int(input())

ret = []


def isPrime(num):
    if num == 1:
        return False
    for i in range(2, int(num**0.5) + 1):
        if num % i == 0:
            return False
    return True


num_c = ["1", "2", "3", "4", "5", "6", "7", "8", "9"]


def go(curr):
    global ret
    if len(curr) == n:
        ret.append(curr)
        return
    for c in num_c:
        if isPrime(int(curr + c)):
            go(curr + c)


go("")

print(*sorted(ret), sep="\n")
