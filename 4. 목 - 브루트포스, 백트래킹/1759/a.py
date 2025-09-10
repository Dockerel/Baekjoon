import sys

input = sys.stdin.readline

l, c = list(map(int, input().split()))

chars = input().split()

aeiou = "aeiou"

moeum = []  # 최소 한 개의 모음(a, e, i, o, u)
jaeum = []  # 최소 두 개의 자음

for c in chars:
    if c in aeiou:
        moeum.append(c)
        continue
    jaeum.append(c)

moeum = sorted(moeum)
jaeum = sorted(jaeum)


def go(mIdx, jIdx, curr):
    if len(curr) == l:
        # 모음 자음 최소 개수 확인
        tempM = 0
        tempJ = 0
        for c in curr:
            if c in aeiou:
                tempM += 1
            else:
                tempJ += 1
        if tempM >= 1 and tempJ >= 2:
            print("".join(curr))
        return

    if mIdx == len(moeum) and jIdx == len(jaeum):
        return
    if mIdx == len(moeum):
        go(mIdx, jIdx + 1, curr + [jaeum[jIdx]])
        go(mIdx, jIdx + 1, curr)
        return
    if jIdx == len(jaeum):
        go(mIdx + 1, jIdx, curr + [moeum[mIdx]])
        go(mIdx + 1, jIdx, curr)
        return
    if moeum[mIdx] < jaeum[jIdx]:
        go(mIdx + 1, jIdx, curr + [moeum[mIdx]])
        go(mIdx + 1, jIdx, curr)
    else:
        go(mIdx, jIdx + 1, curr + [jaeum[jIdx]])
        go(mIdx, jIdx + 1, curr)


go(0, 0, [])
