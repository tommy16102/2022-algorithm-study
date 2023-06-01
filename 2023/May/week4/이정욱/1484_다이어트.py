import sys
sys.setrecursionlimit(10 ** 5)
input = sys.stdin.readline

g = int(input())
arr = [i*i for i in range(1,60000)]

l = 0
r = 1

res = []

while r < len(arr):
    if arr[r] - arr[l] == g:
        # print(arr[l] ** (1/2))
        # print(arr[r] ** (1/2))
        res.append(int(arr[r] ** (1/2)))
        l += 1
        r += 1
    elif arr[r] - arr[l] < g:
        r += 1
    else:
        l += 1

if not res:
    print(-1)
else:
    for e in res:
        print(e)