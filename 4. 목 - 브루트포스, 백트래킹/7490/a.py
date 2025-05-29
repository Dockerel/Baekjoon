def go(n, currStr, currN):
    if currN == n + 1:
        if eval(currStr.replace(" ", "")) == 0:
            print(currStr)
        return
    go(n, currStr + f" {currN}", currN + 1)
    go(n, currStr + f"+{currN}", currN + 1)
    go(n, currStr + f"-{currN}", currN + 1)


for _ in range(int(input())):
    go(int(input()), "1", 2)
    print()
