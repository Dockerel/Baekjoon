import sys

input = sys.stdin.readline

a = [c for c in input().strip()]

ret = 0

curr = 0

starts = ["(", "["]


def go():

    global curr, ret

    st = []
    temp = 0

    mult = 1
    if a[curr] == "(":
        mult = 2
    elif a[curr] == "[":
        mult = 3
    st.append(a[curr])
    curr += 1

    while curr < len(a):
        if len(st) == 0:
            break
        if a[curr] in starts:
            temp += go()
            continue
        else:
            if len(st) == 0:
                print(0)
                exit(0)
            if a[curr] == ")":
                if st[-1] == "(":
                    st.pop()
                else:
                    print(0)
                    exit(0)
            else:
                if st[-1] == "[":
                    st.pop()
                else:
                    print(0)
                    exit(0)
        curr += 1

    if len(st) > 0:
        print(0)
        exit(0)

    return (temp if temp else 1) * mult


while curr < len(a):
    ret += go()

print(ret)
