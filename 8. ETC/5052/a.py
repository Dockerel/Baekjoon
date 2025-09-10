import sys

input = sys.stdin.readline


class Node:
    def __init__(self, key, data=None):
        self.key = key
        self.data = data
        self.children = {}


class Trie:
    def __init__(self):
        self.head = Node(None)

    def insert(self, string):
        curr_node = self.head

        for c in string:
            if curr_node.children.get(c) == None:
                curr_node.children[c] = Node(c)
            curr_node = curr_node.children[c]

        curr_node.data = string

    def check(self, string):
        curr_node = self.head

        for c in string:
            if curr_node.data != None and curr_node.data != string:
                return False
            curr_node = curr_node.children[c]
        return True


t = int(input())
for _ in range(t):
    n = int(input())
    trie = Trie()
    phones = []
    flag = 1
    for i in range(n):
        _str = input().rstrip()
        phones.append(_str)
        trie.insert(_str)
    for phone in phones:
        if not trie.check(phone):
            print("NO")
            flag = 0
            break
    if flag:
        print("YES")
