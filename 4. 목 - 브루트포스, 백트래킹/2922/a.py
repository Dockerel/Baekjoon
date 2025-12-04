import sys, string

input = sys.stdin.readline

s = input()

ret = 0


def verify(s):
    mo = ["A", "E", "I", "O", "U"]
    ja = [c for c in string.ascii_uppercase if c not in mo]

    if "L" not in s:
        return False

    for i in range(len(s) - 2):
        if s[i] in mo and s[i + 1] in mo and s[i + 2] in mo:
            return False
        if s[i] in ja and s[i + 1] in ja and s[i + 2] in ja:
            return False

    return True


def go(s, idx, selected):

    global ret

    if "_" not in s:
        if verify(s):
            tmp = 1
            for c in selected:
                if c == "A":
                    tmp *= 5
                elif c == "B":
                    tmp *= 20
                else:
                    tmp *= 1
            ret += tmp
        return

    for i in range(idx, len(s)):
        if s[i] == "_":
            s = s[:i] + "A" + s[i + 1 :]
            go(s, idx + 1, selected + "A")
            s = s[:i] + "B" + s[i + 1 :]
            go(s, idx + 1, selected + "B")
            s = s[:i] + "L" + s[i + 1 :]
            go(s, idx + 1, selected + "L")
            return


go(s, s.find("_"), "")

print(ret)
