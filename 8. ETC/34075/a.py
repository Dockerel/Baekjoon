import sys

input = sys.stdin.readline

algos = {}
for _ in range(int(input())):
    k, v = input().split()
    algos[k] = int(v)

tiers = {}
for _ in range(int(input())):
    k, v = input().split()
    tiers[k] = int(v)

last_member = None
for _ in range(int(input())):
    query = input().strip()
    if query == "nani ga suki?":
        tier = tiers[last_member]
        temp = {}
        for k, v in algos.items():
            if temp.get(abs(tier - v)) == None:
                temp[abs(tier - v)] = []
            temp[abs(tier - v)].append(k)

        sorted_algo = sorted(temp)[::-1]
        first_algo = sorted(temp[sorted_algo[-1]])[0]
        second_algo = (
            sorted(temp[sorted_algo[-2]])[0]
            if len(temp[sorted_algo[-1]]) == 1
            else sorted(temp[sorted_algo[-1]])[1]
        )
        print(f"{second_algo} yori mo {first_algo}")
    else:
        last_member = query.split(" - ")[0]
        print("hai!")
