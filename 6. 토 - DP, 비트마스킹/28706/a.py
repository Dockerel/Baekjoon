import sys

input = sys.stdin.readline


def cal(num1, op, num2):
    if op == "+":
        return num1 + num2
    return num1 * num2


def go():
    dp = {1}
    for _ in range(int(input())):
        new_dp = set()
        s = input().strip()
        for k in dp:
            temp1 = cal(k, s[0], int(s[2])) % 7
            temp2 = cal(k, s[4], int(s[6])) % 7
            new_dp.add(temp1)
            new_dp.add(temp2)
        dp = new_dp

    print("LUCKY" if 0 in dp else "UNLUCKY")


for _ in range(int(input())):
    go()
