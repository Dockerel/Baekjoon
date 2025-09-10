import sys

input = sys.stdin.readline
sys.setrecursionlimit(10**9)

nodes = []
while 1:
    try:
        nodes.append(int(input()))
    except:
        break


def postorder(start, end):
    if start > end:
        return
    mid = end + 1
    for i in range(start + 1, end + 1):
        if nodes[start] < nodes[i]:
            mid = i
            break
    postorder(start + 1, mid - 1)
    postorder(mid, end)
    print(nodes[start])


postorder(0, len(nodes) - 1)
