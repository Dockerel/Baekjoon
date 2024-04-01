import sys

input = sys.stdin.readline

t = int(input())
for _ in range(t):
    n = int(input())
    cmds = list(map(str, input().rstrip().split()))
    u = [["w"] * 3 for i in range(3)]
    d = [["y"] * 3 for i in range(3)]
    f = [["r"] * 3 for i in range(3)]
    b = [["o"] * 3 for i in range(3)]
    l = [["g"] * 3 for i in range(3)]
    r = [["b"] * 3 for i in range(3)]
    for cmd in cmds:
        if cmd == "U+":
            u = list(zip(*u[::-1]))
            for i in range(3):
                u[i] = list(u[i])
            temp = f[0]
            f[0] = r[0]
            r[0] = b[0]
            b[0] = l[0]
            l[0] = temp
        elif cmd == "U-":
            for i in range(3):
                u = list(zip(*u[::-1]))
            for i in range(3):
                u[i] = list(u[i])
            temp = f[0]
            f[0] = l[0]
            l[0] = b[0]
            b[0] = r[0]
            r[0] = temp
        elif cmd == "D+":
            d = list(zip(*d[::-1]))
            for i in range(3):
                d[i] = list(d[i])
            temp = f[2]
            f[2] = l[2]
            l[2] = b[2]
            b[2] = r[2]
            r[2] = temp
        elif cmd == "D-":
            for i in range(3):
                d = list(zip(*d[::-1]))
            for i in range(3):
                d[i] = list(d[i])
            temp = f[2]
            f[2] = r[2]
            r[2] = b[2]
            b[2] = l[2]
            l[2] = temp
        elif cmd == "F+":
            f = list(zip(*f[::-1]))
            for i in range(3):
                f[i] = list(f[i])
            temp = u[2]
            u[2] = [l[2][2], l[1][2], l[0][2]]
            l[2][2], l[1][2], l[0][2] = d[0]
            d[0] = [r[2][0], r[1][0], r[0][0]]
            r[0][0], r[1][0], r[2][0] = temp
        elif cmd == "F-":
            for i in range(3):
                f = list(zip(*f[::-1]))
            for i in range(3):
                f[i] = list(f[i])
            temp = u[2]
            u[2] = [r[0][0], r[1][0], r[2][0]]
            r[0][0], r[1][0], r[2][0] = d[0][2], d[0][1], d[0][0]
            d[0][2], d[0][1], d[0][0] = l[2][2], l[1][2], l[0][2]
            l[2][2], l[1][2], l[0][2] = temp
        elif cmd == "B+":
            b = list(zip(*b[::-1]))
            for i in range(3):
                b[i] = list(b[i])
            temp = u[0]
            u[0] = [r[0][2], r[1][2], r[2][2]]
            r[0][2], r[1][2], r[2][2] = d[2][2], d[2][1], d[2][0]
            d[2][2], d[2][1], d[2][0] = l[2][0], l[1][0], l[0][0]
            l[2][0], l[1][0], l[0][0] = temp
        elif cmd == "B-":
            for i in range(3):
                b = list(zip(*b[::-1]))
            for i in range(3):
                b[i] = list(b[i])
            temp = u[0]
            u[0] = [l[2][0], l[1][0], l[0][0]]
            l[2][0], l[1][0], l[0][0] = d[2][2], d[2][1], d[2][0]
            d[2][2], d[2][1], d[2][0] = r[0][2], r[1][2], r[2][2]
            r[0][2], r[1][2], r[2][2] = temp
        elif cmd == "L+":
            l = list(zip(*l[::-1]))
            for i in range(3):
                l[i] = list(l[i])
            temp = [u[0][0], u[1][0], u[2][0]]
            u[0][0], u[1][0], u[2][0] = b[2][2], b[1][2], b[0][2]
            b[2][2], b[1][2], b[0][2] = d[0][0], d[1][0], d[2][0]
            d[0][0], d[1][0], d[2][0] = f[0][0], f[1][0], f[2][0]
            f[0][0], f[1][0], f[2][0] = temp
        elif cmd == "L-":
            for i in range(3):
                l = list(zip(*l[::-1]))
            for i in range(3):
                l[i] = list(l[i])
            temp = [u[0][0], u[1][0], u[2][0]]
            u[0][0], u[1][0], u[2][0] = f[0][0], f[1][0], f[2][0]
            f[0][0], f[1][0], f[2][0] = d[0][0], d[1][0], d[2][0]
            d[0][0], d[1][0], d[2][0] = b[2][2], b[1][2], b[0][2]
            b[2][2], b[1][2], b[0][2] = temp
        elif cmd == "R+":
            r = list(zip(*r[::-1]))
            for i in range(3):
                r[i] = list(r[i])
            temp = [u[0][2], u[1][2], u[2][2]]
            u[0][2], u[1][2], u[2][2] = f[0][2], f[1][2], f[2][2]
            f[0][2], f[1][2], f[2][2] = d[0][2], d[1][2], d[2][2]
            d[0][2], d[1][2], d[2][2] = b[2][0], b[1][0], b[0][0]
            b[2][0], b[1][0], b[0][0] = temp
        elif cmd == "R-":
            for i in range(3):
                r = list(zip(*r[::-1]))
            for i in range(3):
                r[i] = list(r[i])
            temp = [u[0][2], u[1][2], u[2][2]]
            u[0][2], u[1][2], u[2][2] = b[2][0], b[1][0], b[0][0]
            b[0][0], b[1][0], b[2][0] = d[2][2], d[1][2], d[0][2]
            d[0][2], d[1][2], d[2][2] = f[0][2], f[1][2], f[2][2]
            f[0][2], f[1][2], f[2][2] = temp

    for i in range(3):
        print(*u[i], sep="")
