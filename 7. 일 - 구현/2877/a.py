4
7

44
47
74
77

444
447
474
# 477(10)
# 744(11)
747
774
777

# 2 4 8 16 32 ...

# 2 6 14 30 62

n = int(input())

curr = 0
k = 2
reps = 0
while 1:
    if curr + k >= n:
        break
    curr += k
    k *= 2
    reps += 1

if n > curr:
    curr += 1
    reps += 1

# print(n - curr, reps)
# print(f"{n} : {reps}자릿수 중 {n-curr+1}번째 수 찾기")


# 477(10) : 10 : 3자릿수 중 4번째 수 찾기 -> 2자릿수 중 4번째 수 찾기 (6) -> 1자릿수 중 2번째 수 찾기 (2)
# 2^reps 의 절반 아래 있으므로 '4'


# 744(11) : 11 : 3자릿수 중 5번째 수 찾기 -> 2자릿수 중 1번째 수 찾기 (3) -> 1자릿수 중 1번째 수 찾기

# 13 : 3자릿수 중 7번째 수 찾기 -> 2자릿수 중 3번째 수 찾기 -> 1자릿수 중 1번째 수 찾기
# -> 774


def go(reps, nth):
    if nth == 0:
        nth = 2**reps
    if reps == 0:
        return
    if nth <= (2**reps) // 2:
        print("4", end="")
    else:
        print("7", end="")
    go(reps - 1, nth % (2 ** (reps - 1)))


go(reps, n - curr + 1)
print()
