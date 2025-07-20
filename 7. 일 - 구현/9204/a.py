import sys

input = sys.stdin.readline


def charToInt(c):
    return ord(c) - ord("A") + 1


def intToChar(n):
    return chr(ord("A") + n - 1)


def inSameLine(sx, sy, ex, ey):
    stepX = 1 if sx < ex else -1
    stepY = 1 if sy < ey else -1

    mult = (ex - sx) // stepX
    return sy + (stepY * mult) == ey


for _ in range(int(input())):
    sx, sy, ex, ey = input().split()
    sx, ex = charToInt(sx), charToInt(ex)
    sy, ey = int(sy), int(ey)
    if (sx + sy) % 2 != (ex + ey) % 2:
        print("Impossible")
        continue
    if sx == ex and sy == ey:
        print(f"0 {intToChar(sx)} {sy}")
        continue
    # 같은 선상에 있는 경우
    if inSameLine(sx, sy, ex, ey):
        print(f"1 {intToChar(sx)} {sy} {intToChar(ex)} {ey}")
        continue
    # 다른 선상에 있는 경우
    setS = set()
    tsx, tsy, tex, tey = sx, sy, ex, ey
    while tsx >= 1 and tsx <= 8 and tsy >= 1 and tsy <= 8:
        setS.add((tsx, tsy))
        tsx, tsy = tsx + 1, tsy + 1
    tsx, tsy, tex, tey = sx, sy, ex, ey
    while tsx >= 1 and tsx <= 8 and tsy >= 1 and tsy <= 8:
        setS.add((tsx, tsy))
        tsx, tsy = tsx + 1, tsy - 1
    tsx, tsy, tex, tey = sx, sy, ex, ey
    while tsx >= 1 and tsx <= 8 and tsy >= 1 and tsy <= 8:
        setS.add((tsx, tsy))
        tsx, tsy = tsx - 1, tsy + 1
    tsx, tsy, tex, tey = sx, sy, ex, ey
    while tsx >= 1 and tsx <= 8 and tsy >= 1 and tsy <= 8:
        setS.add((tsx, tsy))
        tsx, tsy = tsx - 1, tsy - 1
    setE = set()
    tsx, tsy, tex, tey = sx, sy, ex, ey
    while tex >= 1 and tex <= 8 and tey >= 1 and tey <= 8:
        setE.add((tex, tey))
        tex, tey = tex + 1, tey + 1
    tsx, tsy, tex, tey = sx, sy, ex, ey
    while tex >= 1 and tex <= 8 and tey >= 1 and tey <= 8:
        setE.add((tex, tey))
        tex, tey = tex + 1, tey - 1
    tsx, tsy, tex, tey = sx, sy, ex, ey
    while tex >= 1 and tex <= 8 and tey >= 1 and tey <= 8:
        setE.add((tex, tey))
        tex, tey = tex - 1, tey + 1
    tsx, tsy, tex, tey = sx, sy, ex, ey
    while tex >= 1 and tex <= 8 and tey >= 1 and tey <= 8:
        setE.add((tex, tey))
        tex, tey = tex - 1, tey - 1
    midPoint = list(setS.intersection(setE))[0]
    print(
        f"2 {intToChar(sx)} {sy} {intToChar(midPoint[0])} {midPoint[1]} {intToChar(ex)} {ey}"
    )
