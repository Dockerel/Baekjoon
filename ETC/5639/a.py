# 배열로 다시 해보자

import sys

input = sys.stdin.readline


class Node:
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


nodes = []
while 1:
    try:
        nodes.append(Node(int(input())))
    except:
        break

root = nodes[0]
for i in range(1, len(nodes)):
    curr = root
    while 1:
        if nodes[i].data < curr.data:
            if curr.left:
                curr = curr.left
            else:
                curr.left = nodes[i]
                break
        elif nodes[i].data > curr.data:
            if curr.right:
                curr = curr.right
            else:
                curr.right = nodes[i]
                break


def postorder(curr):
    if curr == None:
        return
    postorder(curr.left)
    postorder(curr.right)
    print(curr.data)


postorder(root)
