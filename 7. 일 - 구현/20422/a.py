import sys

input = sys.stdin.readline
d = {
    "A": "A",
    "E": "3",
    "H": "H",
    "I": "I",
    "M": "M",
    "O": "O",
    "S": "2",
    "T": "T",
    "U": "U",
    "V": "V",
    "W": "W",
    "X": "X",
    "Y": "Y",
    "Z": "5",
    "b": "d",
    "d": "b",
    "i": "i",
    "l": "l",
    "m": "m",
    "n": "n",
    "o": "o",
    "p": "q",
    "q": "p",
    "r": "7",
    "u": "u",
    "v": "v",
    "w": "w",
    "x": "x",
    "0": "0",
    "1": "1",
    "2": "S",
    "3": "E",
    "5": "Z",
    "7": "r",
    "8": "8",
}
s = input().strip().lower()
mid = len(s) // 2
left = s[:mid]
right = s[mid if len(s) % 2 == 0 else mid + 1 :][::-1]

ret1 = []
ret2 = []

flag = 1
for i in range(mid):  # 그대로, 대문자화, 그대로 딕셔너리, 대문자화 딕셔너리
    temp1 = [left[i], left[i].upper(), d.get(left[i]), d.get(left[i].upper())]
    temp2 = [right[i], right[i].upper(), d.get(right[i]), d.get(right[i].upper())]

    if temp1[0] == temp2[2]:
        ret1.append(left[i])
        ret2.append(right[i])
        continue
    if temp1[0] == temp2[3]:
        ret1.append(left[i])
        ret2.append(right[i].upper())
        continue

    if temp1[1] == temp2[2]:
        ret1.append(left[i].upper())
        ret2.append(right[i])
        continue
    if temp1[1] == temp2[3]:
        ret1.append(left[i].upper())
        ret2.append(right[i].upper())
        continue

    if temp1[2] == temp2[0]:
        ret1.append(left[i])
        ret2.append(right[i])
        continue
    if temp1[2] == temp2[1]:
        ret1.append(left[i])
        ret2.append(right[i].upper())
        continue

    if temp1[3] == temp2[0]:
        ret1.append(left[i].upper())
        ret2.append(right[i])
        continue
    if temp1[3] == temp2[1]:
        ret1.append(left[i].upper())
        ret2.append(right[i].upper())
        continue

    flag = 0

if flag:
    s1 = "".join(ret1)
    s2 = "".join(ret2[::-1])
    if len(s) % 2 == 1:
        if s[mid] == d.get(s[mid]):
            print(s1 + s[mid] + s2)
        elif s[mid].upper() == d.get(s[mid].upper()):
            print(s1 + s[mid].upper() + s2)
        else:
            print("-1")
    else:
        print(s1 + s2)
else:
    print("-1")
