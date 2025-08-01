import sys

input = sys.stdin.readline

char, use_char, boss = map(int, input().split())
damages = [int(input()) for _ in range(char)]
boss_infos = [list(map(int, input().split())) for _ in range(boss)]


def get_time(hp, damage):
    return (hp // damage) + (1 if hp % damage else 0)


# 캐릭터 개수, 900초
dp = [[-1] * 904 for _ in range(char)]
for i in range(char):
    dp[i][0] = 0

for i in range(char):
    damage = damages[i]
    for j in range(boss):
        hp, money = boss_infos[j]
        attack_time = get_time(hp, damage)
        if attack_time > 900:
            continue
        for k in range(900, attack_time - 1, -1):
            if dp[i][k - attack_time] >= 0:
                dp[i][k] = max(dp[i][k], dp[i][k - attack_time] + money)

ret = []
for i in range(char):
    ret.append(max(dp[i]))
print(sum(sorted(ret, reverse=True)[:use_char]))
