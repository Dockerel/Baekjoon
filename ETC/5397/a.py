import sys

input = sys.stdin.readline

t = int(input())

for _ in range(t):
    s = input().strip()

    st1 = []
    st2 = []

    for c in s:
        if c == "<":
            if st1:
                st2.append(st1.pop())
        elif c == ">":
            if st2:
                st1.append(st2.pop())
        elif c == "-":
            if st1:
                st1.pop()
        else:
            st1.append(c)

    print(*st1, sep="", end="")
    print(*st2[::-1], sep="")
