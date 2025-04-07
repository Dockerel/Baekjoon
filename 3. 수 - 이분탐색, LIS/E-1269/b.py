import sys

input=sys.stdin.readline

a,b=list(map(int,input().split()))

A=set(input().split())
B=set(input().split())

print(len(A.symmetric_difference(B)))