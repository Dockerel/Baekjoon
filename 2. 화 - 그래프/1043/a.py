import sys

input=sys.stdin.readline

n, m = map(int, input().split())
truth_people = list(map(int, input().split()))[1:]

parties = []
parent = list(range(n+4))

def find(x):
    global parent

    if parent[x]!=x:
        parent[x]=find(parent[x])
    return parent[x]

def union(a, b):
    global parent,truth_people

    a = find(a)
    b = find(b)

    if a in truth_people and b in truth_people:
        return

    if a in truth_people:
        parent[b] = a
    
    elif b in truth_people:
        parent[a] = b
    else:
        if a < b:
            parent[b] = a
        
        else:
            parent[a] = b

for _ in range(m):
    party_info = list(map(int, input().split()))
    party_len = party_info[0]
    party = party_info[1:]
    
    for i in range(party_len - 1):
        union(party[i], party[i+1])
    
    parties.append(party)
    
ret = 0
for party in parties:
    flag=1
    for pnum in party:
        if find(pnum) in truth_people:
            flag=0
            break
    
    if flag:
        ret += 1

print(ret)