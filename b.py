n = int(input())

max_star = 1 + 2 * (n - 1)
for i in range(n):
    curr = 1 + 2 * i
    space = (max_star - curr) // 2
    print(" " * space + "*" * curr + " " * space)
