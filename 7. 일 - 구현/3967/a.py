import sys
from itertools import permutations as perm

input = sys.stdin.readline

# ....0....
# .1.2.3.4.
# ..5...6..
# .7.8.9.10.
# ....11....

mem = [-1] * 12

alphas = {chr(i): i - ord("A") for i in range(ord("A"), ord("M"))}
alphas["x"] = -1

targets = [0] * 12

curr = 0
for i in range(5):
    s = input().strip()
    for c in s.replace(".", ""):
        mem[curr] = alphas[c]
        curr += 1
        if c != "x":
            targets[alphas[c]] = 1


def check(memCp):
    temp1 = memCp[1] + memCp[2] + memCp[3] + memCp[4]
    temp2 = memCp[1] + memCp[5] + memCp[8] + memCp[11]
    temp3 = memCp[4] + memCp[6] + memCp[9] + memCp[11]
    temp4 = memCp[0] + memCp[2] + memCp[5] + memCp[7]
    temp5 = memCp[0] + memCp[3] + memCp[6] + memCp[10]
    temp6 = memCp[7] + memCp[8] + memCp[9] + memCp[10]
    return temp1 == temp2 == temp3 == temp4 == temp5 == temp6


def printStar(memCp):
    print(f"....{chr(memCp[0]+ord('A'))}....")
    print(
        f".{chr(memCp[1]+ord('A'))}.{chr(memCp[2]+ord('A'))}.{chr(memCp[3]+ord('A'))}.{chr(memCp[4]+ord('A'))}."
    )
    print(f"..{chr(memCp[5]+ord('A'))}...{chr(memCp[6]+ord('A'))}..")
    print(
        f".{chr(memCp[7]+ord('A'))}.{chr(memCp[8]+ord('A'))}.{chr(memCp[9]+ord('A'))}.{chr(memCp[10]+ord('A'))}."
    )
    print(f"....{chr(memCp[11]+ord('A'))}....")


targetNums = [i for i in range(12) if targets[i] == 0]
for temp in perm(targetNums):
    memCp = mem[:]
    curr = 0
    for i in range(12):
        if memCp[i] == -1:
            memCp[i] = temp[curr]
            curr += 1
    # memCp로 매직 스타 합 검사
    if check(memCp):
        printStar(memCp)
        break
