import sys
from collections import deque

input = sys.stdin.readline


def isPrime(n):
    for i in range(2, int(n**0.5) + 1):
        if n % i == 0:
            return False
    return True


primes = {}
for i in range(1000, 9999 + 1):
    primes[i] = isPrime(i)

for _ in range(int(input())):
    from_num, to_num = input().strip().split()

    from_num = [c for c in from_num]
    to_num = [c for c in to_num]

    visited = {}

    q = deque()
    q.append((from_num, 0))

    flag = False

    while q:
        curr_num, curr_phase = q.popleft()

        if curr_num == to_num:
            print(curr_phase)
            flag = True
            break

        for i in range(4):
            for num in range(0, 9 + 1):
                temp_num = curr_num[:]
                temp_num[i] = str(num)
                temp_num_int = int("".join(temp_num))

                if (
                    1000 <= temp_num_int <= 9999
                    and primes[temp_num_int]
                    and (
                        temp_num_int not in visited
                        or curr_phase + 1 < visited[temp_num_int]
                    )
                ):
                    visited[temp_num_int] = curr_phase + 1
                    q.append((temp_num, curr_phase + 1))

    if not flag:
        print("Impossible")
