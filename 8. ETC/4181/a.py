import sys

def cos(x1, y1, x2, y2, x3, y3):
    a1, a2 = x1 - x3, y1 - y3
    b1, b2 = x2 - x3, y2 - y3
    val = (a1*b1 + a2*b2) / ((a1**2 + a2**2)**(1/2) * (b1**2 + b2**2)**(1/2))
    return round(val, 5)

n = int(sys.stdin.readline())

points = []

for _ in range(n):
    x, y, included = sys.stdin.readline().split()

    if included == "Y":
        points.append([int(x), int(y)])

print(len(points))

points.sort(key=lambda x: (x[0], x[1]))
start = points.pop(0)
print(start[0], start[1])

points.sort(key=lambda x: (x[1], x[0]))
i = 0
while i < len(points):
    if points[i][0] == start[0]:
        i += 1
        continue
    break
#print(start, points)

answer = []

sx, sy = points.pop(i)

keys = set()
dic = dict()
ones = [[sx, sy]]

for point in points:
    x, y = point
    if x-start[0] != 0 and sx-start[0] != 0:
        if (y-start[1]) / (x-start[0]) == (sy-start[1]) / (sx-start[0]):
            ones.append(point)
            continue
    inner = -cos(sx, sy, x, y, start[0], start[1])
    keys.add(inner)
    if inner in dic:
        dic[inner].append(point)
    else:
        dic[inner] = [point]

keys = sorted(list(keys))

ones.sort(key=lambda x: (x[0]))
for element in ones:
    print(element[0], element[1])

for key in keys:
    dic[key].sort(key=lambda x: (-x[1]))
    for element in dic[key]:
        print(element[0], element[1])