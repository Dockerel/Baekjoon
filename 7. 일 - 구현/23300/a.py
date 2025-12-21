import sys

input = sys.stdin.readline

back_page = []
curr_page = None
front_page = []

n, q = map(int, input().split())
for _ in range(q):
    line = input().strip().split()
    cmd = line[0]
    if cmd == "B":
        if len(back_page) == 0:
            continue
        front_page.append(curr_page)
        curr_page = back_page.pop()
    elif cmd == "F":
        if len(front_page) == 0:
            continue
        back_page.append(curr_page)
        curr_page = front_page.pop()
    elif cmd == "A":
        if curr_page:
            back_page.append(curr_page)
        curr_page = line[1]
        front_page = []
    else:  # cmd=="C"
        if len(back_page) == 0:
            continue
        curr = back_page[0]
        temp = []
        for i in range(len(back_page)):
            if curr != back_page[i]:
                temp.append(curr)
                curr = back_page[i]
        temp.append(curr)
        back_page = temp

print(curr_page)

if len(back_page):
    print(*back_page[::-1])
else:
    print(-1)

if len(front_page):
    print(*front_page[::-1])
else:
    print(-1)
