import sys
from itertools import combinations
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

n = int(input())
arr = list(map(int,input().split()))
arr.sort()

ret = 0

for i in range(n):
    tmp = arr[:i] + arr[i+1:]
    l = 0
    r = len(tmp)-1

    while l < r:
        t = tmp[l] + tmp[r]
        if t == arr[i]:
            ret += 1
            break
        if t < arr[i]: l += 1
        else: r -= 1

print(ret)
    

