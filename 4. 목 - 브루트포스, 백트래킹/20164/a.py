import sys

input = sys.stdin.readline

n = [c for c in input().rstrip()]


def go(curr):
    min_ret = float("inf")
    max_ret = -1

    min_temp = max_temp = len([num for num in curr if int(num) % 2])

    if len(curr) == 1:
        return [min_temp, max_temp]

    if len(curr) == 2:
        new_num = int(curr[0]) + int(curr[1])
        temp = go([c for c in str(new_num)])

        min_ret = min_temp + temp[0]
        max_ret = max_temp + temp[1]

        return [min_ret, max_ret]

    # 임의의 위치에서 삼등분
    for i in range(1, len(curr) - 1):
        for j in range(i + 1, len(curr)):
            temp = go(
                [
                    n
                    for n in str(
                        int("".join(curr[:i]))
                        + int("".join(curr[i:j]))
                        + int("".join(curr[j:]))
                    )
                ]
            )

            min_ret = min(min_ret, min_temp + temp[0])
            max_ret = max(max_ret, max_temp + temp[1])

    return [min_ret, max_ret]


print(*go(n))
