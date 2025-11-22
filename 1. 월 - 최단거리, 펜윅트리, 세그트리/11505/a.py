import sys

input = sys.stdin.readline

n, m, k = map(int, input().split())
nums = [int(input()) for _ in range(n)]
tree = [1] * (n + 1)
zero_tree = [0] * (n + 1)

MOD = 1_000_000_007


def mod_inverse(a):
    return pow(a, MOD - 2, MOD)


def update1(index, value):
    while index < len(tree):
        tree[index] = (tree[index] * value) % MOD
        index += index & -index


def update2(index, value):
    while index < len(zero_tree):
        zero_tree[index] += value
        index += index & -index


# 초기화: 0은 1로 치환
for i in range(n):
    if nums[i] == 0:
        update2(i + 1, 1)
    else:
        update1(i + 1, nums[i])


def mult(index):
    ret = 1
    while index > 0:
        ret = (ret * tree[index]) % MOD
        index -= index & -index
    return ret


def _sum(index):
    ret = 0
    while index > 0:
        ret += zero_tree[index]
        index -= index & -index
    return ret


ret = []
for _ in range(m + k):
    cmd, n1, n2 = map(int, input().split())
    if cmd == 1:
        old_val = nums[n1 - 1]

        # 기존 0 카운트 제거
        if old_val == 0:
            update2(n1, -1)

        # 기존 값 제거 (역원 사용)
        if old_val != 0:
            update1(n1, mod_inverse(old_val))
        else:
            update1(n1, mod_inverse(1))

        # 새 값 추가
        if n2 == 0:
            update2(n1, 1)
            update1(n1, 1)  # 0을 1로 저장
        else:
            update1(n1, n2)

        nums[n1 - 1] = n2

    else:
        # 구간에 0이 있는지 확인
        zero_count = _sum(n2) - _sum(n1 - 1)
        if zero_count > 0:
            ret.append(0)
        else:
            # 구간 곱 계산
            if n1 == 1:
                result = mult(n2)
            else:
                result = (mult(n2) * mod_inverse(mult(n1 - 1))) % MOD
            ret.append(result)

print(*ret, sep="\n")
