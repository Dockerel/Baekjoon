import sys

input = sys.stdin.readline

romaToArabian = {"I": 1, "V": 5, "X": 10, "L": 50, "C": 100, "D": 500, "M": 1000}

arabianToRoma = {1: "I", 5: "V", 10: "X", 50: "L", 100: "C", 500: "D", 1000: "M"}
arabianToRomaSpecial = {900: "CM", 400: "CD", 90: "XC", 40: "XL", 9: "IX", 4: "IV"}

for _ in range(int(input())):
    s = input().strip()

    isArabian = True
    try:
        int(s)
    except:
        isArabian = False

    if isArabian:
        currNum = int(s)
        curr = 0
        nums = []
        while currNum:
            nums.append((currNum % 10) * (10**curr))
            currNum //= 10
            curr += 1
        nums.reverse()

        ret = ""
        for i in range(len(nums)):
            num = nums[i]
            if arabianToRomaSpecial.get(num) != None:
                ret += arabianToRomaSpecial[num]
            else:
                currDigits = 10 ** (len(nums) - i - 1)
                temp = num // currDigits
                if temp >= 5:
                    ret += arabianToRoma[5 * currDigits]
                    temp -= 5

                ret += temp * arabianToRoma[currDigits]

        print(ret)
    else:
        ret = 0
        if len(s) == 1:
            print(romaToArabian[s])
            continue
        curr = 0
        while curr < len(s):
            if curr + 1 >= len(s):
                ret += romaToArabian[s[curr]]
                curr += 1
                continue
            temp = romaToArabian[s[curr]] - romaToArabian[s[curr + 1]]
            if temp < 0:
                ret += -temp
                curr += 2
            else:
                ret += romaToArabian[s[curr]]
                curr += 1
        print(ret)
