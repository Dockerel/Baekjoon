G = int(input())

# 현재^2 - 이전^2 = G
# (현재+이전)(현재-이전)=G

ret = []

curr, prev = 1, 1
while 1:
    if curr + prev > G:
        break

    temp = curr**2 - prev**2
    if temp == G:
        ret.append(curr)
        curr += 1
    elif temp < G:
        curr += 1
    else:
        prev += 1

if ret:
    print(*ret, sep="\n")
else:
    print("-1")
