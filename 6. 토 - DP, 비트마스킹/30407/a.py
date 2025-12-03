import sys

input = sys.stdin.readline

n = int(input())
h, d, k = map(int, input().split())
damages = [int(input()) for _ in range(n)]

dp = [[[[-1] * 2 for _ in range(h + 1)] for _ in range(n + 1)] for _ in range(100)]

max_health = -1


def go(
    turn, curr_dist, curr_health, surprise, used_surprise
):  # surprise : i번째에 깜짝 놀라게 하기를 사용하여 i+1번째 공격 무효화

    global max_health, dp

    if curr_health < 0:
        return

    if dp[curr_dist][turn][curr_health][used_surprise] > curr_health:
        return
    else:
        dp[curr_dist][turn][curr_health][used_surprise] = curr_health

    if turn == n:
        if curr_health > 0:
            max_health = max(max_health, curr_health)
        return

    # 1. 웅크리기
    if surprise == 1:
        go(turn + 1, curr_dist, curr_health, 0, used_surprise)
    else:
        damage = max(0, (damages[turn] - curr_dist) // 2)
        go(turn + 1, curr_dist, curr_health - damage, surprise, used_surprise)

    # 2. 네발로 걷기
    if surprise == 1:
        go(turn + 1, curr_dist + k, curr_health, 0, used_surprise)
    else:
        damage = max(0, damages[turn] - curr_dist - k)
        go(turn + 1, curr_dist + k, curr_health - damage, surprise, used_surprise)

    # 3. 깜짝 놀라게 하기
    if used_surprise:
        return
    damage = max(0, damages[turn] - curr_dist)
    go(turn + 1, curr_dist, curr_health - damage, 1, 1)


go(0, d, h, 0, 0)

print(max_health)
