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

    def dfs(self, curr, level):
        print(f"{levelStr*level}{curr.data}")
        for child in curr.children:
            self.dfs(curr.children[child], level + 1)

    def _print(self):
        curr = self.head
        for child in curr.children:
            self.dfs(curr.children[child], 0)


n = int(input())
trie = Trie()
for _ in range(n):
    _list = list(input().rstrip().split())
    trie.insert(_list[1:])
trie._print()
