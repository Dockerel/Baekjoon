import sys

input = sys.stdin.readline

while 1:
    try:
        hole = int(input()) * 10000000
        blocks = sorted([int(input()) for i in range(int(input()))])

        result = None

        left, right = 0, len(blocks) - 1
        while left < right:
            if blocks[left] + blocks[right] == hole:
                result = (blocks[left], blocks[right])
                break
            elif blocks[left] + blocks[right] < hole:
                left += 1
            else:
                right -= 1
        if result:
            print(f"yes {result[0]} {result[1]}")
        else:
            print("danger")
    except:
        break
