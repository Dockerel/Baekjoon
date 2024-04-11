t = int(input())

for _ in range(t):
    n, m = map(int, input().split())
    _list = list(map(int, input().split()))

    ret = 1
    while _list:
        if _list[0] < max(_list):
            _list.append(_list.pop(0))

        else:
            if m == 0:
                break
            _list.pop(0)
            ret += 1

        m = m - 1 if m > 0 else len(_list) - 1
    print(ret)
