dp = [0] * 1001

dp[1] = 10

d = {
    0: [7],
    1: [2, 4],
    2: [1, 3, 5],
    3: [2, 6],
    4: [1, 5, 7],
    5: [2, 4, 6, 8],
    6: [3, 5, 9],
    7: [0, 4, 8],
    8: [5, 7, 9],
    9: [6, 8],
}

curr = [1, 1, 1, 1, 1, 1, 1, 1, 1, 1]
temp = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]
for k in range(2, 1001):
    for i in range(10):
        for num in d[i]:
            temp[num] += curr[i]
    dp[k] = sum(temp) % 1234567
    curr = temp
    temp = [0, 0, 0, 0, 0, 0, 0, 0, 0, 0]


for _ in range(int(input())):
    n = int(input())
    print(dp[n])
