import sys

input = sys.stdin.readline

space = " "


class Node:
    def __init__(self, data):
        self.data = data
        self.children = {}


class Trie:
    def __init__(self):
        self.head = Node(None)

    def insert(self, datas):
        curr = self.head
        # 삽입 -> 정렬 -> 진입
        for i in range(len(datas)):
            if curr.children.get(datas[i]) == None:
                curr.children[datas[i]] = Node(datas[i])
                curr.children = dict(sorted(curr.children.items()))
            curr = curr.children[datas[i]]

    def dfs(self, curr, level):
        print(f"{space*level}{curr.data}")
        for child in curr.children:
            self.dfs(curr.children[child], level + 1)

    def _print(self):
        curr = self.head
        for k in curr.children:
            self.dfs(curr.children[k], 0)


n = int(input())
trie = Trie()
for _ in range(n):
    folders = list(input().rstrip().split("\\"))
    trie.insert(folders)
trie._print()
