import sys

input = sys.stdin.readline

levelStr = "--"


class Node:
    def __init__(self, data):
        self.data = data
        self.children = dict()


class Trie:
    def __init__(self):
        self.head = Node(None)

    def insert(self, datas):
        curr = self.head
        for data in datas:
            if curr.children.get(data) == None:
                curr.children[data] = Node(data)
                curr.children = dict(sorted(curr.children.items()))
            curr = curr.children[data]

    def dfs(self, nodes, level):
        if len(nodes) > 0:
            for node in nodes:
                print(f"{levelStr*level}{node}")
                self.dfs(node, level + 1)

    def _print(self):
        curr = self.head
        for child in curr.children:
            print(child)
            # self.dfs(child, 0)


n = int(input())
trie = Trie()
for _ in range(n):
    _list = list(input().rstrip().split())
    trie.insert(_list[1:])
trie._print()
