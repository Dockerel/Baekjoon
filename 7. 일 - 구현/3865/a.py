import sys

input = sys.stdin.readline

while 1:
    n = int(input())
    if n == 0:
        break

    groups = {}
    first_group = None

    for _ in range(n):
        cmd = input().strip()
        temp = cmd.split(":")
        groups[temp[0]] = temp[1][:-1].split(",")
        if first_group == None:
            first_group = temp[0]

    cache = {}

    def go(curr):
        ret = set()
        if cache.get(curr) != None:
            return cache[curr]
        for member in groups[curr]:
            if groups.get(member) != None:
                ret |= go(member)
            else:
                ret.add(member)
        cache[curr] = ret
        return ret

    print(len(go(first_group)))
