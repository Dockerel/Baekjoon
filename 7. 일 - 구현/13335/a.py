import sys

input = sys.stdin.readline

n, length, weight = map(int, input().split())  # 개수, 길이, 하중
trucks = list(map(int, input().split()))

q = []  # [현재 위치, 무게]

ret = 1
q.append([0, trucks[0]])

curr = 1
while q:
    w_sum = 0
    new_q = []
    # 1. 트럭 한칸씩 이동
    for i in range(len(q)):
        loc, w = q[i]
        if loc + 1 == length:
            continue
        w_sum += w
        new_q.append([loc + 1, w])
    # 2. 트럭 올릴 수 있는지
    if curr < n and w_sum + trucks[curr] <= weight:
        new_q.append([0, trucks[curr]])
        curr += 1
    q = new_q
    ret += 1

print(ret)
