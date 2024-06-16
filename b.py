l1 = []
l2 = []
for _ in range(4):
    l1.append(int(input()))
for _ in range(2):
    l2.append(int(input()))
print(sum(l1) - min(l1) + max(l2))
