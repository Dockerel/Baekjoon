import sys

input = sys.stdin.readline

target = input().strip()
words = [input().strip() for _ in range(int(input()))]

dp = [0] * (len(target) + 1)

for i in range(len(target)):
    if dp[i] or i == 0:
        for word in words:
            if i + len(word) > len(target):
                continue
            flag = 1
            for j in range(len(word)):
                if target[i + j] != word[j]:
                    flag = 0
                    break
            if flag:
                dp[i + len(word)] = 1

print(dp[len(target)])
