import sys

input = sys.stdin.readline

n=int(input())

global gears
gears = []
for i in range(n):
    gear = []
    g = input().rstrip()
    gear.append([int(g[7]), int(g[0]), int(g[1])])
    gear.append([int(g[6]), 0, int(g[2])])
    gear.append([int(g[5]), int(g[4]), int(g[3])])
    gears.append(gear)


def rotate(idx, _dir):
    global gears
    prev = gears[idx]
    if _dir == 1:
        gear = []
        gear.append([prev[1][0], prev[0][0], prev[0][1]])
        gear.append([prev[2][0], 0, prev[0][2]])
        gear.append([prev[2][1], prev[2][2], prev[1][2]])
        gears[idx] = gear
    elif _dir == -1:
        gear = []
        gear.append([prev[0][1], prev[0][2], prev[1][2]])
        gear.append([prev[0][0], 0, prev[2][2]])
        gear.append([prev[1][0], prev[2][0], prev[2][1]])
        gears[idx] = gear


t = int(input())
for _ in range(t):
    curr = [0] * n
    g, d = list(map(int, input().rstrip().split()))
    curr[g - 1] = d
    # g의 왼쪽 설정
    for i in range(g - 2, -1, -1):
        left_g = i
        right_g = i + 1
        if gears[left_g][1][2] == gears[right_g][1][0]:
            break
        else:
            curr[i] = -curr[i + 1]
    # g의 오른쪽 설정
    for i in range(g, n):
        left_g = i - 1
        right_g = i
        if gears[left_g][1][2] == gears[right_g][1][0]:
            break
        else:
            curr[i] = -curr[i - 1]
    # 돌리기:
    for i in range(n):
        rotate(i, curr[i])

ret = 0
for i in range(n):
    ret += 1 if gears[i][0][1] else 0
print(ret)
