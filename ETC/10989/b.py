import sys
from collections import defaultdict

input = sys.stdin.readline

_list = []

n = int(input())
for i in range(n):
    num = int(input())
    _list.append(num)


def MERGE(left, right):
    i, j = 0, 0
    sorted_list = []
    while i < len(left) and j < len(right):
        if left[i] <= right[j]:
            sorted_list.append(left[i])
            i += 1
        else:
            sorted_list.append(right[j])
            j += 1

    while i < len(left):
        sorted_list.append(left[i])
        i += 1
    while j < len(right):
        sorted_list.append(right[j])
        j += 1

    return sorted_list


def MERGE_SORT(A):
    if len(A) <= 1:
        return A

    mid = len(A) // 2
    left = A[:mid]
    right = A[mid:]

    _left = MERGE_SORT(left)
    _right = MERGE_SORT(right)
    return MERGE(_left, _right)


result = MERGE_SORT(_list)
print(*result,sep="\n")
