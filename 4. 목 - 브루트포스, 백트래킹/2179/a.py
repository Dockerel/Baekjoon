import sys

input = sys.stdin.readline

n = int(input())

words = [input().strip() for _ in range(n)]

max_len = -1
ret = None
for i in range(0, n - 1):
    for j in range(i + 1, n):
        w1, w2 = words[i], words[j]
        curr_len = 0
        for k in range(min(len(w1), len(w2))):
            if w1[k] == w2[k]:
                curr_len += 1
            else:
                break
        if max_len < curr_len:
            max_len = curr_len
            ret = (w1, w2)

print(*ret, sep="\n")
